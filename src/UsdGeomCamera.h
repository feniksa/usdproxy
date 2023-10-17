#pragma once

#include "usdlib.h"

#include <pxr/usd/usdGeom/camera.h>

namespace usdproxy
{

class UsdStageWeakPtr;
class SdfPath;
class UsdGeomXformOp;
class TfToken;
class UsdAttribute;
class GfCamera;
class UsdTimeCode;

class UsdGeomCamera
{
public:
	LIBUSDPROXY_API
	UsdGeomCamera() = default;

	LIBUSDPROXY_API
	UsdGeomCamera(const pxr::UsdGeomCamera& usdGeomCamera);

	LIBUSDPROXY_API
	static
	UsdGeomCamera Define(const UsdStageWeakPtr& stage, const SdfPath& path);

	LIBUSDPROXY_API
	UsdGeomXformOp AddTransformOp();

	LIBUSDPROXY_API
	UsdAttribute CreateProjectionAttr(const TfToken& token) const;

	LIBUSDPROXY_API
	GfCamera GetCamera(const UsdTimeCode& timeCode) const;

	LIBUSDPROXY_API
	void SetFromCamera(const GfCamera& camera, const UsdTimeCode& timeCode);

	LIBUSDPROXY_API
	const pxr::UsdGeomCamera& Get() const;
private:
	pxr::UsdGeomCamera m_usdGeomCamera;
};

}