#pragma once

#include "usdlib.h"
#include <pxr/base/plug/plugin.h>

namespace usdproxy
{

class PlugPlugin
{
public:
	LIBUSDPROXY_API
	PlugPlugin() = default;

	LIBUSDPROXY_API
	PlugPlugin(const PlugPlugin&) = default;

	LIBUSDPROXY_API
	explicit PlugPlugin(const pxr::PlugPluginPtr& plugPlugin);

	LIBUSDPROXY_API
	bool IsLoaded() const;

	LIBUSDPROXY_API
	bool Load();

	LIBUSDPROXY_API
	const std::string& GetName() const;

	LIBUSDPROXY_API
	const std::string& GetPath() const;

	LIBUSDPROXY_API
	const pxr::PlugPluginPtr& Get() const;

private:
	pxr::PlugPluginPtr m_plugPlugin;
};

}
