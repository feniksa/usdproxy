#include "UsdGeomXform.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"

namespace usdproxy
{
UsdGeomXform::UsdGeomXform(const pxr::UsdGeomXform& usdGeomXform)
: m_usdGeomXform(usdGeomXform)
{
}

UsdGeomXform UsdGeomXform::Define(UsdStageWeakPtr& stage, const SdfPath& path)
{
	return UsdGeomXform(pxr::UsdGeomXform::Define(stage.Get(), path.Get()));
}

SdfPath UsdGeomXform::GetPath() const
{
	return SdfPath(m_usdGeomXform.GetPath());
}

UsdGeomXformOp UsdGeomXform::AddTransformOp() const
{
	return {m_usdGeomXform.AddTransformOp() };
}

}