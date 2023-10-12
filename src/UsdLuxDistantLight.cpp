#include "UsdLuxDistantLight.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"

namespace usdproxy
{
UsdLuxDistantLight::UsdLuxDistantLight(pxr::UsdLuxDistantLight&& usdLuxDistantLight)
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
}

