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
  void saveGeometryAndState(QByteArray& mwGeom,
                            QByteArray& mwState,
                            QByteArray& hsState,
                            QByteArray& vslState,
                            QByteArray& vsrState);
  void restoreGeometryAndState(const QByteArray& mwGeom,
                               const QByteArray& mwState,
                               const QByteArray& hsState,
                               const QByteArray& vslState,
                               const QByteArray& vsrState);

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
