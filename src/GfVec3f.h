#pragma once

#include "usdlib.h"

#include <pxr/base/gf/vec3f.h>

namespace usdproxy
{

class GfVec3d;

class GfVec3f
{
public:
	LIBUSDPROXY_API
	explicit GfVec3f() = default;

	LIBUSDPROXY_API
	explicit GfVec3f(const GfVec3f& gfVec3f);

	LIBUSDPROXY_API
	explicit GfVec3f(const pxr::GfVec3f& gfVec3f);

	LIBUSDPROXY_API
	explicit GfVec3f(const GfVec3d& gfVec3d);

	LIBUSDPROXY_API
	explicit GfVec3f(float x, float y, float z);

	LIBUSDPROXY_API
	const pxr::GfVec3f& Get() const;

private:
	pxr::GfVec3f m_gfVec3f;
};

}