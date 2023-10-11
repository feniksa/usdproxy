#pragma once

#include "usdlib.h"
#include <pxr/base/gf/vec2f.h>

namespace usdproxy
{
class GfVec2f
{
public:
	LIBUSDPROXY_API
	GfVec2f() = default;

	LIBUSDPROXY_API
	explicit GfVec2f(float x, float y);

	LIBUSDPROXY_API
	GfVec2f(const GfVec2f&) = default;

	LIBUSDPROXY_API
	const pxr::GfVec2f& Get() const;
private:
	pxr::GfVec2f m_gfVec2f;
};
}