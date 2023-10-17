#pragma once

#include "usdlib.h"
#include <pxr/usd/usdLux/domeLight.h>

namespace usdproxy
{

class UsdStageWeakPtr;
class SdfPath;
class SdfAssetPath;
class UsdAttribute;
class TfToken;

class UsdLuxDomeLight
{
public:
	LIBUSDPROXY_API
	UsdLuxDomeLight() = default;

	LIBUSDPROXY_API
	UsdLuxDomeLight(const pxr::UsdLuxDomeLight& usdLuxDomeLight);

	LIBUSDPROXY_API
	static
	UsdLuxDomeLight Define(const UsdStageWeakPtr& stage, const SdfPath& path);

	LIBUSDPROXY_API
	UsdAttribute CreateTextureFileAttr(const SdfAssetPath& sdfAssetPath);

	LIBUSDPROXY_API
	UsdAttribute CreateTextureFormatAttr(const TfToken& token);

	LIBUSDPROXY_API
	const pxr::UsdLuxDomeLight& Get() const;
private:
	pxr::UsdLuxDomeLight m_usdLuxDomeLight;
};
}