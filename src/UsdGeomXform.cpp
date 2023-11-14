#include "UsdGeomXform.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "UsdSchemaBase.h"
#include "UsdGeomXformOpArray.h";

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
	return UsdGeomXformOp(m_usdGeomXform.AddTransformOp());
}

UsdGeomXformOp UsdGeomXform::AddRotateXYZOp() const
{
	return UsdGeomXformOp(m_usdGeomXform.AddRotateXYZOp());
}

bool UsdGeomXform::SetXformOpOrder(const UsdGeomXformOpArray& orderedXformOps,
					 bool resetXformStack) const
{
	return m_usdGeomXform.SetXformOpOrder(orderedXformOps.Get(), resetXformStack);
}

UsdGeomXformOp UsdGeomXform::AddTranslateOp() const
{
	return UsdGeomXformOp(m_usdGeomXform.AddTranslateOp());
}

UsdGeomXformOp UsdGeomXform::AddOrientOp() const
{
	return UsdGeomXformOp(m_usdGeomXform.AddOrientOp());
}

UsdGeomXformOp UsdGeomXform::AddScaleOp() const
{
	return UsdGeomXformOp(m_usdGeomXform.AddScaleOp());
}

UsdSchemaBase UsdGeomXform::GetUsdSchemaBase() const
{
	return UsdSchemaBase(m_usdGeomXform);
}

const pxr::UsdGeomXform& UsdGeomXform::Get() const
{
	return m_usdGeomXform;
}

}