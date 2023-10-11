#pragma once

#include "usdlib.h"

#include <pxr/base/vt/types.h>
#include <pxr/base/vt/array.h>
#include <pxr/base/gf/quath.h>

namespace usdproxy
{

class GfQuath;

class VtQuathArray
{
public:
	LIBUSDPROXY_API
	VtQuathArray() = default;

	LIBUSDPROXY_API
	explicit VtQuathArray(size_t size);

	LIBUSDPROXY_API
	void push_back(const GfQuath& quath);

	LIBUSDPROXY_API
	const pxr::VtQuathArray& Get() const;
private:
	pxr::VtQuathArray m_vtQuathArray;
};

}