#pragma once

#include "usdlib.h"

#include <pxr/base/gf/vec3d.h>

namespace usdproxy
{

class GfVec3d
{
public:
	LIBUSDPROXY_API
	explicit GfVec3d() = default;

	LIBUSDPROXY_API
	explicit GfVec3d(const GfVec3d&) = default;

	LIBUSDPROXY_API
	GfVec3d(pxr::GfVec3d&& gfVec3D);

	LIBUSDPROXY_API
	GfVec3d(const pxr::GfVec3d& gfVec3D);

	LIBUSDPROXY_API
	explicit GfVec3d(double x, double y, double z);

	LIBUSDPROXY_API
	double operator[](int index) const;

	LIBUSDPROXY_API
	double Value(int index) const;


	LIBUSDPROXY_API
	const pxr::GfVec3d& Get() const;

private:
	pxr::GfVec3d m_gfVec3d;
};

}