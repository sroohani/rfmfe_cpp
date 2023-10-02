#include "config.h"

#define CFGGRP_UI "UI"

#define CFGKEY_MW_GEOMETRY "MainWindowGeometry"
#define CFGKEY_MW_STATE    "MainWindowState"
#define CFGKEY_HS_STATE    "HorizontalSplitterState"
#define CFGKEY_VSL_STATE   "VerticalSplitterLeftState"
#define CFGKEY_VSR_STATE   "VerticalSplitterRightState"

#include <QSettings>
#include <QApplication>

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
}
