#pragma once

#include "usdlib.h"
#include "UsdPrim.h"
#include <pxr/usd/usdGeom/scope.h>

namespace usdproxy
{

class SdfPath;
class UsdStageWeakPtr;

class UsdGeomScope
{
public:
	LIBUSDPROXY_API
	explicit UsdGeomScope(const pxr::UsdGeomScope& usdGeomScope);

	LIBUSDPROXY_API
	explicit UsdGeomScope(const UsdPrim& prim = UsdPrim());

	LIBUSDPROXY_API
	static
	UsdGeomScope Define(const UsdStageWeakPtr &stage, const SdfPath &path);

private:
	pxr::UsdGeomScope m_usdGeomScope;
};

}