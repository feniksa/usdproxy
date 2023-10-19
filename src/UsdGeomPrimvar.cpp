#include "UsdGeomPrimvar.h"
#include "UsdAttribute.h"
#include "VtIntArray.h"
#include "VtVec2iArray.h"

namespace usdproxy
{

UsdGeomPrimvar::UsdGeomPrimvar(const pxr::UsdGeomPrimvar& usdGeomPrimvar)
: m_usdGeomPrimvar(usdGeomPrimvar)
{
}

UsdAttribute UsdGeomPrimvar::GetAttr() const
{
	return { m_usdGeomPrimvar.GetAttr() };
}

bool UsdGeomPrimvar::SetIndices(const VtIntArray& array, const UsdTimeCode& timeCode)
{
	return m_usdGeomPrimvar.SetIndices(array.Get());
}
bool UsdGeomPrimvar::SetInterpolation(const UsdGeomTokens::Token& token)
{
	return SetInterpolation(UsdGeomTokens(token));
}

bool UsdGeomPrimvar::SetInterpolation(const UsdGeomTokens& token)
{
	return m_usdGeomPrimvar.SetInterpolation(token.toPxrToken());
}

bool UsdGeomPrimvar::Set(const VtVec2iArray& array, const UsdTimeCode& timeCode)
{
	return m_usdGeomPrimvar.Set(array.Get(), timeCode.Get());
}

}