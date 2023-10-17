#pragma once

#include "usdlib.h"
#include "UsdGeomTokens.h"
#include <pxr/usd/usdGeom/primvar.h>

namespace usdproxy
{

class UsdAttribute;
class VtIntArray;

class UsdGeomPrimvar
{
public:
	LIBUSDPROXY_API
	UsdGeomPrimvar() = default;

	LIBUSDPROXY_API
	UsdGeomPrimvar(const pxr::UsdGeomPrimvar& usdGeomPrimvar);

	LIBUSDPROXY_API
	UsdAttribute GetAttr() const;

	LIBUSDPROXY_API
	bool SetIndices(const VtIntArray& array);

	LIBUSDPROXY_API
	bool SetInterpolation(const UsdGeomTokens& token);

	LIBUSDPROXY_API
	bool SetInterpolation(const UsdGeomTokens::Token& token);
private:
	pxr::UsdGeomPrimvar m_usdGeomPrimvar;
};

}