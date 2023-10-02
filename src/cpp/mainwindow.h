#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSplitter;
class QTableWidget;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  QSplitter *m_hSplitter{},
            *m_vSplitterLeft{},
            *m_vSplitterRight{};
  QTableWidget *m_lContents{},
               *m_lProps{},
               *m_rContents{},
               *m_rProps{};
};
#endif // MAINWINDOW_H
