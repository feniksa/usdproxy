#pragma once

#include "usdlib.h"
#include <pxr/base/gf/quath.h>

namespace usdproxy
{

class GfHalf;
class GfQuatd;

class GfQuath
{
public:
	LIBUSDPROXY_API
	GfQuath() = default;

	LIBUSDPROXY_API
	explicit GfQuath(GfHalf realVal);

	LIBUSDPROXY_API
	explicit GfQuath(const GfQuatd& gfQuatd);

	LIBUSDPROXY_API
	explicit GfQuath(GfHalf real, GfHalf i, GfHalf j, GfHalf k);

	// alias for GfHalf
	LIBUSDPROXY_API
	explicit GfQuath(float real, float i, float j, float k);

	LIBUSDPROXY_API
	explicit GfQuath(const pxr::GfQuath& gfQuath);

	LIBUSDPROXY_API
	const pxr::GfQuath& Get() const;
private:
	pxr::GfQuath m_gfQuath;
};
}