#pragma once

#include "usdlib.h"
#include "SdfPath.h"

#include <pxr/usd/usdGeom/xform.h>
#include "UsdGeomXformOp.h"

namespace usdproxy
{

class UsdStageWeakPtr;
class SdfPath;
class UsdSchemaBase;
class UsdGeomXformOpArray;

class UsdGeomXform
{
public:
	LIBUSDPROXY_API
	explicit UsdGeomXform() = default;

	LIBUSDPROXY_API
	UsdGeomXform(const pxr::UsdGeomXform& usdGeomXform);

	LIBUSDPROXY_API
	static
	UsdGeomXform Define(UsdStageWeakPtr& stage, const SdfPath& path);

	LIBUSDPROXY_API
	UsdGeomXform(const UsdGeomXform&) = default;

	LIBUSDPROXY_API
	UsdGeomXformOp AddTransformOp() const;

	LIBUSDPROXY_API
	UsdGeomXformOp AddOrientOp() const;

	LIBUSDPROXY_API
	UsdGeomXformOp AddScaleOp() const;

	LIBUSDPROXY_API
	UsdGeomXformOp AddTranslateOp() const;

	LIBUSDPROXY_API
	UsdGeomXformOp AddRotateXYZOp() const;

	LIBUSDPROXY_API
	bool SetXformOpOrder(const UsdGeomXformOpArray& orderedXformOps,
						 bool resetXformStack = false) const;

	LIBUSDPROXY_API
	UsdSchemaBase GetUsdSchemaBase() const;

	LIBUSDPROXY_API
	SdfPath GetPath() const;

	LIBUSDPROXY_API
	const pxr::UsdGeomXform& Get() const;
private:
	pxr::UsdGeomXform m_usdGeomXform;
};

}