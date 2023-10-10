#include "UsdPrim.h"

#include "UsdStageWeakPtr.h"
#include "SdfPath.h"

namespace usdproxy
{

const pxr::UsdPrim& UsdPrim::Get() const
{
	return m_usdPrim;
}

UsdPrim::UsdPrim(pxr::UsdPrim&& usdPrim) noexcept
: m_usdPrim(usdPrim)
{
}


UsdStageWeakPtr UsdPrim::GetStage() const
{
	return UsdStageWeakPtr(m_usdPrim.GetStage());
}

SdfPath UsdPrim::GetPath() const
{
	return SdfPath(m_usdPrim.GetPath());
}

}