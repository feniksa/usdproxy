#pragma once

#include "usdlib.h"
#include "GfVec3f.h"

#include <pxr/base/vt/array.h>

namespace usdproxy
{

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