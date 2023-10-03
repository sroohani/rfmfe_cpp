#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <QByteArray>

class QSplitter;
class QComboBox;
class QTableWidget;
class QToolBar;
class QLineEdit;
class QPushButton;
class QNetworkAccessManager;
class QNetworkReply;

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
  void saveNetworkConfig(QString& remoteHost);
  void restoreNetworkConfig(const QString& remoteHost);

private:
  Ui::MainWindow *ui;
  QSplitter *m_hSplitter{},
            *m_vSplitterLeft{},
            *m_vSplitterRight{};
  QComboBox *m_lRoots{},
            *m_rRoots{};
  QTableWidget *m_lContents{},
               *m_lProps{},
               *m_rContents{},
               *m_rProps{};
  QToolBar *m_toolBar{};
  QLineEdit *m_remoteEdit{};
  QPushButton *m_goButton{};
  QNetworkAccessManager *m_netAccMgr{};
  QNetworkReply *m_netRep{};
  QByteArray m_dataBuff;
};
#endif // MAINWINDOW_H
