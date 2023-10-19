#pragma once

#include "usdlib.h"
#include "GfVec2i.h"
#include <pxr/base/vt/value.h>
#include <pxr/base/vt/types.h>
#include <pxr/base/vt/array.h>

namespace usdproxy
{
class VtVec2iArray
{
public:
	LIBUSDPROXY_API
	VtVec2iArray() = default;

	LIBUSDPROXY_API
	void push_back(const GfVec2i& point);

	LIBUSDPROXY_API
	const pxr::VtVec2iArray& Get() const;

private:
	pxr::VtVec2iArray m_vtVec2iArray;
};

}