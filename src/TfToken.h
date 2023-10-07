#pragma once

#include "usdlib.h"
#include <pxr/usd/usd/tokens.h>

namespace usdproxy
{
class TfToken
{
public:
	LIBUSDPROXY_API
	explicit TfToken(const std::string& value);

	LIBUSDPROXY_API
	const pxr::TfToken& Get() const;
private:
	pxr::TfToken m_tfToken;
};
}