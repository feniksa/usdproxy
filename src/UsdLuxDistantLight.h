#pragma once

#include "usdlib.h"
#include <pxr/usd/usdLux/distantLight.h>

namespace usdproxy
{

class UsdStageWeakPtr;
class SdfPath;
class UsdAttribute;

class UsdLuxDistantLight
{
public:
	LIBUSDPROXY_API
	UsdLuxDistantLight() = default;

	LIBUSDPROXY_API
	UsdLuxDistantLight(pxr::UsdLuxDistantLight&& usdLuxDistantLight);

	LIBUSDPROXY_API
	static
	UsdLuxDistantLight Define(const UsdStageWeakPtr& stage, const SdfPath& path);

	LIBUSDPROXY_API
	UsdAttribute CreateAngleAttr(float angle);

	LIBUSDPROXY_API
	UsdAttribute CreateIntensityAttr(float intensity);

	LIBUSDPROXY_API
	const pxr::UsdLuxDistantLight& Get() const;
private:
	pxr::UsdLuxDistantLight m_usdLuxDistantLight;
};
}