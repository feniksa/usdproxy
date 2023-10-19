#pragma once

#include "usdlib.h"

#include <pxr/usd/usdGeom/tokens.h>

namespace usdproxy
{

class UsdGeomTokens
{
public:
	enum Token
	{
		faceVarying,
		varying
	};

	LIBUSDPROXY_API
	explicit UsdGeomTokens(Token token = Token::faceVarying);

	LIBUSDPROXY_API
	const pxr::TfToken toPxrToken() const;

	LIBUSDPROXY_API
	const pxr::TfToken Get() const;
private:
	Token m_token; // hide TfToken type
};

}