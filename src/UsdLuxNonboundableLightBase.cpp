#include "UsdLuxNonboundableLightBase.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "UsdAttribute.h"
#include "GfVec3f.h"
#include "UsdGeomXformOp.h"

namespace usdproxy
{

UsdLuxNonboundableLightBase::UsdLuxNonboundableLightBase(const pxr::UsdLuxNonboundableLightBase& usdLuxNonboundableLightBase)
: m_usdLuxNonboundableLightBase(usdLuxNonboundableLightBase)
{
}

UsdLuxNonboundableLightBase UsdLuxNonboundableLightBase::Get(const UsdStageWeakPtr& stage, const SdfPath& path)
{
	return pxr::UsdLuxNonboundableLightBase::Get(stage.Get(), path.Get());
}

const pxr::UsdLuxNonboundableLightBase& UsdLuxNonboundableLightBase::Get() const
{
	return m_usdLuxNonboundableLightBase;
}

UsdAttribute UsdLuxNonboundableLightBase::CreateColorAttr(const GfVec3f& color) const
{
	const pxr::VtValue value(color.Get());
	return m_usdLuxNonboundableLightBase.CreateColorAttr(value);
}

UsdAttribute UsdLuxNonboundableLightBase::CreateExposureAttr(float exposure) const
{
	const pxr::VtValue value(exposure);
	return m_usdLuxNonboundableLightBase.CreateExposureAttr(value);
}

UsdGeomXformOp UsdLuxNonboundableLightBase::AddTransformOp() const
{
	return UsdGeomXformOp(m_usdLuxNonboundableLightBase.AddTransformOp());
}

}