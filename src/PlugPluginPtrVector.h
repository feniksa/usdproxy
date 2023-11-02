#pragma once

#include "usdlib.h"
#include <pxr/base/plug/registry.h>

namespace usdproxy
{
class PlugPlugin;

class PlugPluginPtrVector
{
public:
	LIBUSDPROXY_API
	PlugPluginPtrVector() = default;

	LIBUSDPROXY_API
	PlugPluginPtrVector(const PlugPluginPtrVector&) = default;

	LIBUSDPROXY_API
	PlugPluginPtrVector(const pxr::PlugPluginPtrVector& plugPluginPtrVector);

	LIBUSDPROXY_API
	int Size() const;

	LIBUSDPROXY_API
	PlugPlugin Get(int index);

	LIBUSDPROXY_API
	const pxr::PlugPluginPtrVector& Get() const;
private:
	pxr::PlugPluginPtrVector m_plugPluginPtrVector;
};
}