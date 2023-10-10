#pragma once

#include "usdlib.h"
#include <pxr/usd/usdShade/output.h>

namespace usdproxy
{

class UsdShadeConnectableAPI;
class TfToken;

class UsdShadeOutput
{
public:
	LIBUSDPROXY_API
	UsdShadeOutput(pxr::UsdShadeOutput&& usdShadeOutput);

	LIBUSDPROXY_API
	bool ConnectToSource(const UsdShadeConnectableAPI& api, const TfToken& path);

	LIBUSDPROXY_API
	const pxr::UsdShadeOutput& Get() const;

private:
	pxr::UsdShadeOutput m_usdShadeOutput;
};

}