#pragma once

#include "usdlib.h"
#include "UsdPrim.h"
#include "KindToken.h"
#include <pxr/usd/usd/modelAPI.h>

namespace usdproxy
{

class TfToken;
class UsdSchemaBase;
class UsdGeomXform;

class UsdModelAPI
{
public:
	LIBUSDPROXY_API
	UsdModelAPI(const UsdPrim& usdPrim = UsdPrim());

	LIBUSDPROXY_API
	UsdModelAPI(const pxr::UsdSchemaBase& usdSchemaBase);

	LIBUSDPROXY_API
	UsdModelAPI(const UsdGeomXform& usdGeomXform);

	LIBUSDPROXY_API
	UsdModelAPI(const UsdSchemaBase& usdSchemaBase);

	LIBUSDPROXY_API
	bool SetKind(const TfToken& token);

	LIBUSDPROXY_API
	bool SetKind(const KindToken::KindTokens& token);

	LIBUSDPROXY_API
	const pxr::UsdModelAPI& Get() const;
private:
	pxr::UsdModelAPI m_usdModelAPI;
};
}