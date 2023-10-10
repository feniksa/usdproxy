#pragma once

#include <pxr/usd/usd/attribute.h>
#include "usdlib.h"


namespace usdproxy
{

class UsdAttribute
{
public:
	LIBUSDPROXY_API
	UsdAttribute() = default;

	LIBUSDPROXY_API
	UsdAttribute(pxr::UsdAttribute&& usdAttribute);
private:
	pxr::UsdAttribute m_usdAttribute;
};

}