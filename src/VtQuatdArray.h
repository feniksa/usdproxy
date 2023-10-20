#pragma once

#include "usdlib.h"

#include <pxr/base/vt/types.h>
#include <pxr/base/vt/array.h>
#include <pxr/base/gf/quath.h>

namespace usdproxy
{

class GfQuatd;

class VtQuatdArray
{
public:
	LIBUSDPROXY_API
	VtQuatdArray() = default;

	LIBUSDPROXY_API
	explicit VtQuatdArray(size_t size);

	LIBUSDPROXY_API
	void push_back(const GfQuatd& quath);

	LIBUSDPROXY_API
	const pxr::VtQuatdArray& Get() const;
private:
	pxr::VtQuatdArray m_vtQuathArray;
};

}