#include "UsdGeomPrimvar.h"
#include "UsdAttribute.h"
#include "VtIntArray.h"

namespace usdproxy
{

UsdGeomPrimvar::UsdGeomPrimvar(pxr::UsdGeomPrimvar&& usdGeomPrimvar)
: m_usdGeomPrimvar(std::move(usdGeomPrimvar))
{
}

UsdAttribute UsdGeomPrimvar::GetAttr() const
{
	return { m_usdGeomPrimvar.GetAttr() };
}

bool UsdGeomPrimvar::SetIndices(const VtIntArray& array)
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

}