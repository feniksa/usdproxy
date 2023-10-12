#include "UsdLuxDomeLight.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "SdfAssetPath.h"
#include "UsdAttribute.h"
#include "TfToken.h"

namespace usdproxy
{

UsdLuxDomeLight::UsdLuxDomeLight(pxr::UsdLuxDomeLight&& usdLuxDomeLight)
: m_usdLuxDomeLight(usdLuxDomeLight)
{
}

UsdLuxDomeLight UsdLuxDomeLight::Define(const UsdStageWeakPtr& stage, const SdfPath& path)
{
	return { pxr::UsdLuxDomeLight::Define(stage.Get(), path.Get()) };
}

UsdAttribute UsdLuxDomeLight::CreateTextureFileAttr(const usdproxy::SdfAssetPath &sdfAssetPath)
{
	const pxr::VtValue value(sdfAssetPath.Get());
	return { m_usdLuxDomeLight.CreateTextureFileAttr(value) };
}

UsdAttribute UsdLuxDomeLight::CreateTextureFormatAttr(const TfToken& token)
{
	const pxr::VtValue value(token.Get());
	return { m_usdLuxDomeLight.CreateTextureFormatAttr(value) };
}

const pxr::UsdLuxDomeLight& UsdLuxDomeLight::Get() const
{
	return m_usdLuxDomeLight;
}

}