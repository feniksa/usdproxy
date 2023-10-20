#pragma once

#include "usdlib.h"
#include <pxr/base/vt/array.h>

namespace usdproxy
{

class GfVec3f;

class VtVec3fArray
{
public:
	LIBUSDPROXY_API
	void push_back(const GfVec3f& xyz);

	LIBUSDPROXY_API
	const pxr::VtVec3fArray& Get() const;
private:
	pxr::VtVec3fArray  m_vtVec3fArray;
};

}