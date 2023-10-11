#pragma once

#include "usdlib.h"
#include "pxr/usd/usd/relationship.h"

namespace usdproxy
{
class SdfPath;

class UsdRelationship
{
public:
	LIBUSDPROXY_API
	UsdRelationship() = default;

	LIBUSDPROXY_API
	UsdRelationship(pxr::UsdRelationship&& usdRelationship);

	LIBUSDPROXY_API
	bool AddTarget(const SdfPath& path);

	LIBUSDPROXY_API
	const pxr::UsdRelationship& Get() const;
private:
	pxr::UsdRelationship m_usdRelationShip;
};

}