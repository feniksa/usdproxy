#pragma once

#include "usdlib.h"
#include "GfVec2f.h"

#include <pxr/base/vt/value.h>
#include <pxr/base/vt/types.h>
#include <pxr/base/vt/array.h>

namespace usdproxy
{
class VtVec2fArray
{
public:
	LIBUSDPROXY_API
	VtVec2fArray() = default;

	LIBUSDPROXY_API
	void push_back(const GfVec2f& point);

	LIBUSDPROXY_API
	const pxr::VtVec2fArray& Get() const;

private:
	pxr::VtVec2fArray m_vtVec2fArray;
};

}
