#include "PlugPlugin.h"

namespace usdproxy
{

PlugPlugin::PlugPlugin(const pxr::PlugPluginPtr& plugPlugin)
: m_plugPlugin(plugPlugin)
{
}

const pxr::PlugPluginPtr& PlugPlugin::Get() const
{
	return m_plugPlugin;
}

bool PlugPlugin::IsLoaded() const
{
	return m_plugPlugin->IsLoaded();
}

bool PlugPlugin::Load()
{
	return m_plugPlugin->Load();
}

const std::string& PlugPlugin::GetName() const
{
	return m_plugPlugin->GetName();
}

const std::string& PlugPlugin::GetPath() const
{
	return m_plugPlugin->GetPath();
}

}