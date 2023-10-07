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
		faceVarying
	};

	LIBUSDPROXY_API
	UsdGeomTokens(Token token = Token::faceVarying);

	LIBUSDPROXY_API
	pxr::TfToken toPxrToken();
private:
	Token m_token; // hide TfToken type
};

}