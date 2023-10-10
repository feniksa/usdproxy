#pragma once

#include "usdlib.h"
#include <pxr/usd/usdShade/material.h>

namespace usdproxy
{

class UsdStageWeakPtr;
class SdfPath;

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
private:
	pxr::UsdShadeMaterial m_usdShadeMaterial;
};

} // namespace usdproxy
