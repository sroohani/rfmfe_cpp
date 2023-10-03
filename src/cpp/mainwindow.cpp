#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSplitter>
#include <QComboBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QToolBar>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

constexpr int RootRole = Qt::UserRole + 1;
constexpr int FileRole = RootRole + 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  m_hSplitter      = new QSplitter(this);
  m_vSplitterLeft  = new QSplitter(m_hSplitter);
  m_vSplitterRight = new QSplitter(m_hSplitter);
  m_vSplitterLeft->setOrientation(Qt::Vertical);
  m_vSplitterRight->setOrientation(Qt::Vertical);
  m_lRoots = new QComboBox(m_vSplitterLeft);
  m_lContents = new QTableWidget(m_vSplitterLeft);
  m_lContents->insertColumn(0);
  m_lContents->verticalHeader()->hide();
  m_lContents->horizontalHeader()->hide();
  m_lProps = new QTableWidget(m_vSplitterLeft);
  m_rRoots = new QComboBox(m_vSplitterRight);
  m_rContents = new QTableWidget(m_vSplitterRight);
  m_rContents->insertColumn(0);
  m_rContents->verticalHeader()->hide();
  m_rContents->horizontalHeader()->hide();
  m_rProps = new QTableWidget(m_vSplitterRight);
  setCentralWidget(m_hSplitter);

  m_toolBar = new QToolBar(this);
  m_toolBar->setObjectName("MainToolBar");
  m_toolBar->addWidget(new QLabel(tr("Remote host: ")));
  m_toolBar->addWidget(new QLabel("http://"));
  m_remoteEdit = new QLineEdit();
  m_toolBar->addWidget(m_remoteEdit);
  m_goButton = new QPushButton(tr("&Go"));
  m_toolBar->addWidget(m_goButton);
  m_netAccMgr = new QNetworkAccessManager(this);
  connect(m_goButton, &QPushButton::clicked, [this](bool)
  {
    QString remoteHost(m_remoteEdit->text());
    if (!remoteHost.endsWith("/"))
    {
      remoteHost.append("/");
    }
    remoteHost.prepend("http://");
    QNetworkRequest req{QUrl(remoteHost)};
    m_dataBuff.clear();
    m_netRep = m_netAccMgr->get(req);
    connect(m_netRep, &QNetworkReply::readyRead, [this]()
    {
      m_dataBuff.append(m_netRep->readAll());
    });

    connect(m_netRep, &QNetworkReply::finished, [this]()
    {
      if (m_netRep->error() != QNetworkReply::NoError)
      {
        QMessageBox::critical(this, tr("Error"), m_netRep->errorString());
      }
      else
      {
        QJsonObject jsonObj = QJsonDocument::fromJson(m_dataBuff).object();
        const QJsonArray& roots = jsonObj.value("roots").toArray();
        if (!roots.empty())
        {
          for (const auto& r: roots)
          {
            m_lRoots->addItem(r.toString());
            m_rRoots->addItem(r.toString());
          }
          m_lRoots->setCurrentIndex(0);
          m_rRoots->setCurrentIndex(0);
        }
        m_lContents->clearContents();
        m_lProps->clearContents();
        m_rContents->clearContents();
        m_rProps->clearContents();
      }
    });
  });
  addToolBar(Qt::TopToolBarArea, m_toolBar);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::saveGeometryAndState(QByteArray& mwGeom,
                                      QByteArray& mwState,
                                      QByteArray& hsState,
                                      QByteArray& vslState,
                                      QByteArray& vsrState)
{
  mwGeom = saveGeometry();
  mwState    = saveState();
  hsState = m_hSplitter->saveState();
  vslState = m_vSplitterLeft->saveState();
  vsrState = m_vSplitterRight->saveState();
}

void MainWindow::restoreGeometryAndState(const QByteArray& mwGeom,
                                         const QByteArray& mwState,
                                         const QByteArray& hsState,
                                         const QByteArray& vslState,
                                         const QByteArray& vsrState)
{
  restoreGeometry(mwGeom);
  restoreState(mwState);
  m_hSplitter->restoreState(hsState);
  m_vSplitterLeft->restoreState(vslState);
  m_vSplitterRight->restoreState(vsrState);
}

void MainWindow::saveNetworkConfig(QString& remoteHost)
{
  remoteHost = m_remoteEdit->text();
}

void MainWindow::restoreNetworkConfig(const QString& remoteHost)
{
  m_remoteEdit->setText(remoteHost);
}
