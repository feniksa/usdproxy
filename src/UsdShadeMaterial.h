#pragma once

#include "usdlib.h"
#include <pxr/usd/usdShade/material.h>

namespace usdproxy
{

class UsdStageWeakPtr;
class SdfPath;
class UsdShadeOutput;

class UsdShadeMaterial
{
public:
	LIBUSDPROXY_API
	UsdShadeMaterial();

	LIBUSDPROXY_API
	UsdShadeMaterial(pxr::UsdShadeMaterial&& usdShadeMaterial);

	LIBUSDPROXY_API
	static
	UsdShadeMaterial Define(const UsdStageWeakPtr& stage, const SdfPath& path);

	LIBUSDPROXY_API
	UsdShadeOutput CreateSurfaceOutput();

	LIBUSDPROXY_API
	SdfPath GetPath() const;
private:
	pxr::UsdShadeMaterial m_usdShadeMaterial;
};

} // namespace usdproxy
