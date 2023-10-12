#pragma once

#include <pxr/usd/usd/attribute.h>
#include "usdlib.h"

namespace usdproxy
{

class VtVec2fArray;

class UsdAttribute
{
public:
	LIBUSDPROXY_API
	UsdAttribute() = default;

	LIBUSDPROXY_API
	UsdAttribute(const pxr::UsdAttribute& usdAttribute);

	LIBUSDPROXY_API
	UsdAttribute(pxr::UsdAttribute&& usdAttribute);

	LIBUSDPROXY_API
	bool Set(const VtVec2fArray& array);
private:
	pxr::UsdAttribute m_usdAttribute;
};

}