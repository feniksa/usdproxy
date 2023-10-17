#pragma once

#include "usdlib.h"

#include <pxr/base/vt/array.h>

namespace usdproxy
{

class VtIntArray
{
public:
	LIBUSDPROXY_API
	VtIntArray() = default;

	LIBUSDPROXY_API
	VtIntArray(const VtIntArray& other);

	LIBUSDPROXY_API
	VtIntArray(VtIntArray&& other) noexcept;

	LIBUSDPROXY_API
	void push_back(int data);

	LIBUSDPROXY_API
	const pxr::VtIntArray& Get() const;
private:
	pxr::VtIntArray m_vtIntArray;
};

}