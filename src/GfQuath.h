#pragma once

#include "usdlib.h"
#include <pxr/base/gf/quath.h>

namespace usdproxy
{
class GfQuath
{
public:
	LIBUSDPROXY_API
	GfQuath() = default;

	LIBUSDPROXY_API
	GfQuath(pxr::GfQuath&& gfQuath);

	LIBUSDPROXY_API
	GfQuath(const pxr::GfQuath& gfQuath);

	LIBUSDPROXY_API
	const pxr::GfQuath& Get() const;
private:
	pxr::GfQuath m_gfQuath;
};
}