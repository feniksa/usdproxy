#include "UsdGeomCamera.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "UsdGeomXformOp.h"
#include "TfToken.h"
#include "UsdAttribute.h"
#include "UsdTimeCode.h"
#include "GfCamera.h"

namespace usdproxy
{

UsdGeomCamera::UsdGeomCamera(pxr::UsdGeomCamera&& usdGeomCamera)
: m_usdGeomCamera(std::move(usdGeomCamera))
{
}

UsdGeomCamera UsdGeomCamera::Define(const UsdStageWeakPtr& stage, const SdfPath& path)
{
	return { pxr::UsdGeomCamera::Define(stage.Get(), path.Get() ) };
}

const pxr::UsdGeomCamera& UsdGeomCamera::Get() const
{
	return m_usdGeomCamera;
}

UsdGeomXformOp UsdGeomCamera::AddTransformOp()
{
	return { m_usdGeomCamera.AddTransformOp() };
}


UsdAttribute UsdGeomCamera::CreateProjectionAttr(const TfToken& token) const
{
	const pxr::VtValue value(token.Get());
	return { m_usdGeomCamera.CreateProjectionAttr(value) };
}

GfCamera UsdGeomCamera::GetCamera(const UsdTimeCode& timeCode) const
{
	return { m_usdGeomCamera.GetCamera(timeCode.Get()) };
}

void UsdGeomCamera::SetFromCamera(const GfCamera& camera, const UsdTimeCode& timeCode)
{
	m_usdGeomCamera.SetFromCamera(camera.Get(), timeCode.Get());
}

}