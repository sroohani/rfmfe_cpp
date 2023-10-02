#include "config.h"

#include <QSettings>

#define CFGGRP_UI  "UI"
#define CFGGRP_NET "Network"

#define CFGKEY_MW_GEOMETRY "MainWindowGeometry"
#define CFGKEY_MW_STATE    "MainWindowState"
#define CFGKEY_HS_STATE    "HorizontalSplitterState"
#define CFGKEY_VSL_STATE   "VerticalSplitterLeftState"
#define CFGKEY_VSR_STATE   "VerticalSplitterRightState"

#define CFGKEY_RMT_HOST "RemoteHost"

Config::Config()
{

}

void Config::load()
{
  QSettings cfg;

  cfg.beginGroup(CFGGRP_UI);
  m_mwGeometry          = cfg.value(CFGKEY_MW_GEOMETRY).toByteArray();
  m_mwState             = cfg.value(CFGKEY_MW_STATE).toByteArray();
  m_hSplitterState      = cfg.value(CFGKEY_HS_STATE).toByteArray();
  m_vSplitterLeftState  = cfg.value(CFGKEY_VSL_STATE).toByteArray();
  m_vSplitterRightState = cfg.value(CFGKEY_VSR_STATE).toByteArray();
  cfg.endGroup();

  cfg.beginGroup(CFGGRP_NET);
  m_remoteHost = cfg.value(CFGKEY_RMT_HOST).toString();
  cfg.endGroup();
}

void Config::save()
{
  QSettings cfg;

  cfg.beginGroup(CFGGRP_UI);
  cfg.setValue(CFGKEY_MW_GEOMETRY, m_mwGeometry);
  cfg.setValue(CFGKEY_MW_STATE, m_mwState);
  cfg.setValue(CFGKEY_HS_STATE, m_hSplitterState);
  cfg.setValue(CFGKEY_VSL_STATE, m_vSplitterLeftState);
  cfg.setValue(CFGKEY_VSR_STATE, m_vSplitterRightState);
  cfg.endGroup();

  cfg.beginGroup(CFGGRP_NET);
  cfg.setValue(CFGKEY_RMT_HOST, m_remoteHost);
  cfg.endGroup();
}
