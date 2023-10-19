#pragma once

#include "usdlib.h"
#include <pxr/base/gf/vec2f.h>

namespace usdproxy
{
class GfVec2i
{
public:
	LIBUSDPROXY_API
	GfVec2i() = default;

	LIBUSDPROXY_API
	explicit GfVec2i(int x, int y);

	LIBUSDPROXY_API
	GfVec2i(const GfVec2i&) = default;

	LIBUSDPROXY_API
	const pxr::GfVec2i& Get() const;
private:
	pxr::GfVec2i m_gfVec2f;
};
}