#pragma once

#include "usdlib.h"
#include "SdfPath.h"

#include <pxr/usd/usdGeom/xformOp.h>

namespace usdproxy
{

class GfMatrix4d;

class UsdGeomXformOp
{
public:
	LIBUSDPROXY_API
	explicit UsdGeomXformOp() = default;

	LIBUSDPROXY_API
	UsdGeomXformOp(pxr::UsdGeomXformOp&& usdGeomXformOp) noexcept;

	LIBUSDPROXY_API
	bool Set(const GfMatrix4d& matrix);

	LIBUSDPROXY_API
	const pxr::UsdGeomXformOp& Get() const;

private:
	pxr::UsdGeomXformOp m_usdGeomXformOp;
};

}