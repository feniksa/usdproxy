#include "UsdGeomPrimvarsAPI.h"
#include "SdfValueTypeName.h"
#include "UsdGeomPrimvar.h"

namespace usdproxy
{

UsdGeomPrimvarsAPI::UsdGeomPrimvarsAPI(const UsdPrim& prim)
: m_usdGeomPrimvarsAPI(prim.Get())
{
}

const pxr::UsdGeomPrimvarsAPI& UsdGeomPrimvarsAPI::Get() const
{
	return m_usdGeomPrimvarsAPI;
}

UsdGeomPrimvar UsdGeomPrimvarsAPI::CreatePrimvar(const TfToken& token, const SdfValueTypeName::SdfValueTypeNames &typeName, const TfToken& interpolation)
{
	return CreatePrimvar(token, SdfValueTypeName(typeName), interpolation);
}

UsdGeomPrimvar UsdGeomPrimvarsAPI::CreatePrimvar(const TfToken& token, const SdfValueTypeName &typeName, const TfToken& interpolation)
{
	return m_usdGeomPrimvarsAPI.CreatePrimvar(token.Get(), typeName.Get(), interpolation.Get());
}

UsdGeomPrimvar UsdGeomPrimvarsAPI::CreatePrimvar(const TfToken& token, const SdfValueTypeName::SdfValueTypeNames &typeName, const UsdGeomTokens::Token& interpolation)
{
	return m_usdGeomPrimvarsAPI.CreatePrimvar(token.Get(), SdfValueTypeName(typeName).Get(), UsdGeomTokens(interpolation).toPxrToken());
}

}