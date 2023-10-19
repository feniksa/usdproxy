#pragma once

#include "usdlib.h"
#include "TfToken.h"
#include "pxr/usd/kind/registry.h"

namespace usdproxy
{
class KindToken
{
public:
	enum KindTokens
	{
		component
	};

	LIBUSDPROXY_API
	KindToken(KindTokens token = KindTokens::component)
	{
	}

	LIBUSDPROXY_API
	TfToken Get() const;

private:
	KindTokens m_token;

};
}