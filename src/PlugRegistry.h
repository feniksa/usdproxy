#pragma once

#include "usdlib.h"
#include <pxr/base/plug/registry.h>

namespace usdproxy
{
class PlugPluginPtrVector;

class PlugRegistry 
{
public:
	LIBUSDPROXY_API
	PlugRegistry() = default;

	LIBUSDPROXY_API
	PlugRegistry(const PlugRegistry& plugRegistry) = default;

	LIBUSDPROXY_API
	static
	PlugPluginPtrVector RegisterPlugins(const std::string& pathToPlugInfo);

	LIBUSDPROXY_API
	static
	PlugPluginPtrVector GetAllPlugins();
private:
};

}
