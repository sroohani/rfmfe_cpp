#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "global_defs.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;

  w.setWindowTitle(APP_NAME);

//  QObject::connect(&a, &QApplication::aboutToQuit, [&curl]()
//                   {
//                   });

  w.show();
  return a.exec();
}
