#pragma once

#include "usdlib.h"
#include "UsdPrim.h"
#include "TfToken.h"
#include "SdfValueTypeName.h"
#include "UsdGeomTokens.h"
#include <pxr/usd/usdGeom/primvarsAPI.h>

namespace usdproxy
{

class UsdGeomPrimvar;

class UsdGeomPrimvarsAPI
{
public:
	LIBUSDPROXY_API
	UsdGeomPrimvarsAPI(const UsdPrim& prim = UsdPrim());

	LIBUSDPROXY_API
	UsdGeomPrimvarsAPI(const UsdGeomPrimvarsAPI& usdGeomPrimvarsApi) = default;

	LIBUSDPROXY_API
	UsdGeomPrimvar CreatePrimvar(const TfToken& token, const SdfValueTypeName &typeName, const TfToken& interpolation = TfToken());

	LIBUSDPROXY_API
	UsdGeomPrimvar CreatePrimvar(const TfToken& token, const SdfValueTypeName::SdfValueTypeNames &typeName, const TfToken& interpolation = TfToken());

	LIBUSDPROXY_API
	UsdGeomPrimvar CreatePrimvar(const TfToken& token, const SdfValueTypeName::SdfValueTypeNames &typeName, const UsdGeomTokens::Token& interpolation);

	LIBUSDPROXY_API
	const pxr::UsdGeomPrimvarsAPI& Get() const;
private:
	pxr::UsdGeomPrimvarsAPI m_usdGeomPrimvarsAPI;
};

} // namespace
