#pragma once

#include "usdlib.h"
#include <pxr/usd/usd/timeCode.h>

namespace usdproxy
{

class UsdTimeCode
{
public:
	LIBUSDPROXY_API
	UsdTimeCode() = default;

	LIBUSDPROXY_API
	explicit UsdTimeCode(double time);

	LIBUSDPROXY_API
	UsdTimeCode(const pxr::UsdTimeCode& usdTimeCode);

	LIBUSDPROXY_API
	const pxr::UsdTimeCode& Get() const;

private:
	pxr::UsdTimeCode m_usdTimeCode;
};

}