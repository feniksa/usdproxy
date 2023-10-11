#pragma once

#include "usdlib.h"
#include "SdfPath.h"

#include <pxr/usd/usdGeom/xform.h>
#include "UsdGeomXformOp.h"

namespace usdproxy
{

class UsdStageWeakPtr;
class SdfPath;

class UsdGeomXform
{
public:
	LIBUSDPROXY_API
	explicit UsdGeomXform() = default;

	LIBUSDPROXY_API
	static
	UsdGeomXform Define(UsdStageWeakPtr& stage, const SdfPath& path);

	LIBUSDPROXY_API
	explicit UsdGeomXform(pxr::UsdGeomXform&& usdGeomXform);

	LIBUSDPROXY_API
	explicit UsdGeomXform(const UsdGeomXform&) = default;

	LIBUSDPROXY_API
	UsdGeomXform& operator=(const UsdGeomXform& other) = default;

	LIBUSDPROXY_API
	UsdGeomXformOp AddTransformOp() const;

	LIBUSDPROXY_API
	SdfPath GetPath() const;
private:
	pxr::UsdGeomXform m_usdGeomXform;
};

}