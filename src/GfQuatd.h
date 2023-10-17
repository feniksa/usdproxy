#pragma once

#include "usdlib.h"
#include <pxr/base/gf/quatd.h>

namespace usdproxy
{

class GfVec3d;

class GfQuatd
{
public:
	LIBUSDPROXY_API
	GfQuatd() = default;

	LIBUSDPROXY_API
	GfQuatd(const GfQuatd&) = default;

	LIBUSDPROXY_API
	GfQuatd(const pxr::GfQuatd& gfQuatd);

	LIBUSDPROXY_API
	double GetReal() const;

	LIBUSDPROXY_API
	GfVec3d GetImaginary() const;

	LIBUSDPROXY_API
	const pxr::GfQuatd& Get() const;
private:
	pxr::GfQuatd m_gfQuatd;
};

}