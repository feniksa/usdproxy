#pragma once

#include "usdlib.h"
#include <pxr/usd/usd/prim.h>

namespace usdproxy
{

class UsdPrim
{
public:
	LIBUSDPROXY_API
	UsdPrim() = default;

	LIBUSDPROXY_API
	UsdPrim(const UsdPrim&) = default;

	LIBUSDPROXY_API
	UsdPrim& operator=(const UsdPrim&) = default;

	LIBUSDPROXY_API
	UsdPrim(pxr::UsdPrim&& usdPrim) noexcept;

	LIBUSDPROXY_API
	const pxr::UsdPrim& Get() const;
private:
	pxr::UsdPrim m_usdPrim;
};

}
