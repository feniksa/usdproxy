#pragma once

#include "usdlib.h"
#include "SdfPath.h"

#include <pxr/usd/usdGeom/xformOp.h>

namespace usdproxy
{

class GfMatrix4d;
class GfQuath;
class GfQuatd;
class GfVec3f;
class GfVec3d;

class UsdGeomXformOp
{
public:
	LIBUSDPROXY_API
	explicit UsdGeomXformOp() = default;

	LIBUSDPROXY_API
	explicit UsdGeomXformOp(const pxr::UsdGeomXformOp& usdGeomXformOp);

	LIBUSDPROXY_API
	bool Set(const GfMatrix4d& matrix);

	LIBUSDPROXY_API
	bool Set(const GfQuath& quath);

	LIBUSDPROXY_API
	bool Set(const GfQuatd& quatd);

	LIBUSDPROXY_API
	bool Set(const GfVec3f& gfVec3f);

	LIBUSDPROXY_API
	bool Set(const GfVec3d& gfVec3d);

	LIBUSDPROXY_API
	const pxr::UsdGeomXformOp& Get() const;
private:
	pxr::UsdGeomXformOp m_usdGeomXformOp;
};

}