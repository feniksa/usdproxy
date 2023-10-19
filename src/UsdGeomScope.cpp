#include "UsdGeomScope.h"
#include "UsdStagePtr.h"
#include "SdfPath.h"

namespace usdproxy
{

UsdGeomScope::UsdGeomScope(const pxr::UsdGeomScope& usdGeomScope)
: m_usdGeomScope(usdGeomScope)
{
}

UsdGeomScope::UsdGeomScope(const usdproxy::UsdPrim &prim)
: m_usdGeomScope(prim.Get())
{
}

UsdGeomScope UsdGeomScope::Define(const UsdStageWeakPtr &stage, const SdfPath &path)
{
	return UsdGeomScope(pxr::UsdGeomScope::Define(stage.Get(), path.Get()));
}

}