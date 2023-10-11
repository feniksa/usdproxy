#pragma once

#include "usdlib.h"
#include <pxr/base/gf/half.h>

namespace usdproxy
{
class GfHalf
{
public:
	LIBUSDPROXY_API
	GfHalf() = default;

	LIBUSDPROXY_API
	explicit GfHalf(float h);

	LIBUSDPROXY_API
	const pxr::GfHalf& Get() const;
private:
	pxr::GfHalf m_gfHalf;
};

}