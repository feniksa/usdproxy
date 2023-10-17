#pragma once

#include "usdlib.h"
#include <pxr/usd/usd/prim.h>
#include <string>

namespace usdproxy
{

class UsdStageWeakPtr;
class SdfPath;

class UsdPrim
{
public:
	LIBUSDPROXY_API
	UsdPrim() = default;

	LIBUSDPROXY_API
	UsdPrim(const UsdPrim& usdPrim);

	LIBUSDPROXY_API
	UsdPrim(const pxr::UsdPrim& usdPrim);

	LIBUSDPROXY_API
	const pxr::UsdPrim& Get() const;

	LIBUSDPROXY_API
	UsdStageWeakPtr GetStage() const;

	LIBUSDPROXY_API
	SdfPath GetPath() const;

	LIBUSDPROXY_API
	bool GetReferences_AddReference(const std::string& identifier, const SdfPath& primPath);

private:
	pxr::UsdPrim m_usdPrim;
};

}
