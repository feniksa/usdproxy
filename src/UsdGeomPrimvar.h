#pragma once

#include "usdlib.h"
#include "UsdGeomTokens.h"
#include "UsdTimeCode.h"
#include <pxr/usd/usdGeom/primvar.h>

namespace usdproxy
{

class UsdAttribute;
class VtIntArray;
class VtVec2iArray;

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
	bool SetIndices(const VtIntArray& array, const UsdTimeCode& timeCode = UsdTimeCode());

	LIBUSDPROXY_API
	bool SetInterpolation(const UsdGeomTokens& token);

	LIBUSDPROXY_API
	bool SetInterpolation(const UsdGeomTokens::Token& token);

	LIBUSDPROXY_API
	bool Set(const VtVec2iArray& array, const UsdTimeCode& timeCode = UsdTimeCode());
private:
	pxr::UsdGeomPrimvar m_usdGeomPrimvar;
};

}