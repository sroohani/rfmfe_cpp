#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSplitter>
#include <QTableWidget>
#include <QToolBar>
#include <QLineEdit>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  m_toolBar = new QToolBar(this);
  m_toolBar->setObjectName("MainToolBar");
  m_toolBar->addWidget(new QLabel(tr("Remote host: ")));
  m_toolBar->addWidget(new QLabel("http://"));
  m_remoteEdit = new QLineEdit();
  m_toolBar->addWidget(m_remoteEdit);
  addToolBar(Qt::TopToolBarArea, m_toolBar);

  m_hSplitter      = new QSplitter(this);
  m_vSplitterLeft  = new QSplitter(m_hSplitter);
  m_vSplitterRight = new QSplitter(m_hSplitter);
  m_vSplitterLeft->setOrientation(Qt::Vertical);
  m_vSplitterRight->setOrientation(Qt::Vertical);
  m_lContents = new QTableWidget(m_vSplitterLeft);
  m_lProps = new QTableWidget(m_vSplitterLeft);
  m_rContents = new QTableWidget(m_vSplitterRight);
  m_rProps = new QTableWidget(m_vSplitterRight);
  setCentralWidget(m_hSplitter);
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
