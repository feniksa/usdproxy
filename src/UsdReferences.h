#pragma once

#include "usdlib.h"
#include <pxr/usd/usd/references.h>

namespace usdproxy
{
class SdfPath;

class UsdReferences
{
public:
	LIBUSDPROXY_API
	UsdReferences() = default;

	LIBUSDPROXY_API
	UsdReferences(UsdReferences&& usdReferences);

	LIBUSDPROXY_API
	UsdReferences(pxr::UsdReferences&& usdReferences);

	LIBUSDPROXY_API
	UsdReferences& Emplace(pxr::UsdReferences&& usdReferences);

	LIBUSDPROXY_API
	bool IsInvalid() const;

	LIBUSDPROXY_API
	bool AddReference(const std::string&, const SdfPath& path);

	LIBUSDPROXY_API
	const pxr::UsdReferences& Get() const;
private:
	std::unique_ptr<pxr::UsdReferences> m_usdReferences;
};
}