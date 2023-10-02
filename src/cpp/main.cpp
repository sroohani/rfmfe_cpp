#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "global_defs.h"
#include "config.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  Config cfg;

  a.setApplicationName(APP_NAME);
  a.setOrganizationName(ORG_NAME);

  cfg.load();

  w.setWindowTitle(APP_DISP_NAME);
  w.restoreGeometryAndState(cfg.m_mwGeometry, cfg.m_mwState,
                            cfg.m_hSplitterState,
                            cfg.m_vSplitterLeftState,
                            cfg.m_vSplitterRightState);

  QObject::connect(&a, &QApplication::aboutToQuit, [&cfg, &w]()
  {
    w.saveGeometryAndState(cfg.m_mwGeometry, cfg.m_mwState,
                           cfg.m_hSplitterState,
                           cfg.m_vSplitterLeftState,
                           cfg.m_vSplitterRightState);
    cfg.save();
  });

  w.show();
  return a.exec();
}
