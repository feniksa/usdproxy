#pragma once

#include <pxr/usd/usd/schemaBase.h>
#include "usdlib.h"

namespace usdproxy
{
class UsdSchemaBase
{
public:
	LIBUSDPROXY_API
	UsdSchemaBase() = default;

	LIBUSDPROXY_API
	UsdSchemaBase(const UsdSchemaBase& usdSchemaBase) = default;

	LIBUSDPROXY_API
	UsdSchemaBase(const pxr::UsdSchemaBase& usdSchemaBase);

	LIBUSDPROXY_API
	const pxr::UsdSchemaBase& Get() const;
private:
	pxr::UsdSchemaBase m_usdSchemaBase;
};
}