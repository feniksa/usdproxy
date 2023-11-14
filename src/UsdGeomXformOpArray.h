#pragma once

#include "usdlib.h"
#include <pxr/usd/usdGeom/xformOp.h>

namespace usdproxy
{

class UsdGeomXformOp;

class UsdGeomXformOpArray
{
public:
	LIBUSDPROXY_API
	UsdGeomXformOpArray() = default;

	LIBUSDPROXY_API
	UsdGeomXformOpArray(const UsdGeomXformOpArray&) = default;

	LIBUSDPROXY_API
	void push_back(const pxr::UsdGeomXformOp& operation);

	LIBUSDPROXY_API
	void push_back(const UsdGeomXformOp& operation);

	LIBUSDPROXY_API
	const std::vector<pxr::UsdGeomXformOp>& Get() const;
private:
	std::vector<pxr::UsdGeomXformOp> m_usdGeomXformOpArray;
};
}