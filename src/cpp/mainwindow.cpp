#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSplitter>
#include <QTableWidget>

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

