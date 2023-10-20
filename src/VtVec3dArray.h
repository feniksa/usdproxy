#pragma once

#include "usdlib.h"

#include <pxr/base/vt/array.h>

namespace usdproxy
{

class GfVec3d;

class VtVec3dArray
{
public:
	LIBUSDPROXY_API
	void push_back(const GfVec3d& xyz);

	LIBUSDPROXY_API
	const pxr::VtVec3dArray& Get() const;
private:
	pxr::VtVec3dArray m_vtVec3dArray;
};

}
