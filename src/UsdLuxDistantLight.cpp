#include "UsdLuxDistantLight.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "UsdAttribute.h"

namespace usdproxy
{
UsdLuxDistantLight::UsdLuxDistantLight(const pxr::UsdLuxDistantLight& usdLuxDistantLight)
: m_usdLuxDistantLight(usdLuxDistantLight)
{
}

UsdLuxDistantLight UsdLuxDistantLight::Define(const UsdStageWeakPtr& stage, const SdfPath& path)
{
	return { pxr::UsdLuxDistantLight::Define(stage.Get(), path.Get()) };
}

const pxr::UsdLuxDistantLight& UsdLuxDistantLight::Get() const
{
	return m_usdLuxDistantLight;
}

UsdAttribute UsdLuxDistantLight::CreateAngleAttr(float angle)
{
	const pxr::VtValue value(angle);
	return { m_usdLuxDistantLight.CreateAngleAttr(value) };
}

UsdAttribute UsdLuxDistantLight::CreateIntensityAttr(float intensity)
{
	const pxr::VtValue value(intensity);
	return { m_usdLuxDistantLight.CreateIntensityAttr(value) };
}

}

