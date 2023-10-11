#pragma once

#include "usdlib.h"
#include <pxr/base/gf/vec2d.h>

namespace usdproxy
{
class GfVec2d
{
public:
	LIBUSDPROXY_API
	GfVec2d() = default;

	LIBUSDPROXY_API
	explicit GfVec2d(double x, double y);

	LIBUSDPROXY_API
	GfVec2d(const GfVec2d&) = default;

	LIBUSDPROXY_API
	const pxr::GfVec2d& Get() const;
private:
	pxr::GfVec2d m_gfVec2d;
};
}