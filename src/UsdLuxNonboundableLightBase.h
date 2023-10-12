#pragma once

#include "usdlib.h"
#include <pxr/usd/usdLux/nonboundableLightBase.h>

namespace usdproxy
{

class UsdStageWeakPtr;
class SdfPath;
class UsdAttribute;
class GfVec3f;
class UsdGeomXformOp;

class UsdLuxNonboundableLightBase
{
public:
	LIBUSDPROXY_API
	UsdLuxNonboundableLightBase() = default;

	LIBUSDPROXY_API
	UsdLuxNonboundableLightBase(pxr::UsdLuxNonboundableLightBase&& usdLuxNonboundableLightBase);

	LIBUSDPROXY_API
	static
	UsdLuxNonboundableLightBase Get(const UsdStageWeakPtr& stage, const SdfPath& path);

	LIBUSDPROXY_API
	UsdAttribute CreateColorAttr(const GfVec3f& color) const;

	LIBUSDPROXY_API
	UsdAttribute CreateExposureAttr(float exposure) const;

	LIBUSDPROXY_API
	UsdGeomXformOp AddTransformOp() const;

	LIBUSDPROXY_API
	const pxr::UsdLuxNonboundableLightBase& Get() const;
private:
	pxr::UsdLuxNonboundableLightBase m_usdLuxNonboundableLightBase;
};

}