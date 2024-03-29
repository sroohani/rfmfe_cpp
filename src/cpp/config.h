#ifndef CONFIG_H
#define CONFIG_H

#include <QByteArray>
#include <QString>

class Config
{
public:
  Config();

  void load();
  void save();

  QByteArray m_mwGeometry,
             m_mwState,
             m_hSplitterState,
             m_vSplitterLeftState,
             m_vSplitterRightState;
  QString m_remoteHost;
};

#endif // CONFIG_H
