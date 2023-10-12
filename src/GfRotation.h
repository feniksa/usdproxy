#pragma once

#include "usdlib.h"
#include <pxr/base/gf/rotation.h>

namespace usdproxy
{

class GfQuatd;
class GfVec3d;

class GfRotation
{
public:
	LIBUSDPROXY_API
	GfRotation() = default;

	LIBUSDPROXY_API
	GfRotation(const GfRotation&) = default;

	LIBUSDPROXY_API
	GfRotation(const pxr::GfRotation& gfRotation);

	LIBUSDPROXY_API
	explicit GfRotation(const GfVec3d& rotateFrom, const GfVec3d& rotateTo);

	LIBUSDPROXY_API
	GfQuatd GetQuat() const;

	LIBUSDPROXY_API
	const pxr::GfRotation& Get() const;
private:
	pxr::GfRotation m_gfRotation;
};

}