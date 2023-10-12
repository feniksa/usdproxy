#pragma once

#include "usdlib.h"
#include <pxr/usd/usdGeom/pointInstancer.h>

namespace usdproxy
{

class UsdStageWeakPtr;
class SdfPath;
class UsdRelationship;
class VtIntArray;
class VtVec3fArray;
class VtQuathArray;
class UsdAttribute;

class UsdGeomPointInstancer
{
public:
	LIBUSDPROXY_API
	UsdGeomPointInstancer() = default;

	LIBUSDPROXY_API
	UsdGeomPointInstancer(const UsdGeomPointInstancer&) = default;

	LIBUSDPROXY_API
	UsdGeomPointInstancer(pxr::UsdGeomPointInstancer&& usdGeomPointInstancer);

	LIBUSDPROXY_API
	static
	UsdGeomPointInstancer Define(const UsdStageWeakPtr &stage, const SdfPath &path);

	LIBUSDPROXY_API
	UsdRelationship GetPrototypesRel();

	LIBUSDPROXY_API
	UsdAttribute CreateProtoIndicesAttr(const VtIntArray& value);

	LIBUSDPROXY_API
	UsdAttribute CreatePositionsAttr(const VtVec3fArray& value);

	LIBUSDPROXY_API
	UsdAttribute CreateOrientationsAttr(const VtQuathArray&);

	LIBUSDPROXY_API
	const pxr::UsdGeomPointInstancer& Get() const;
private:
	pxr::UsdGeomPointInstancer m_usdGeomPointInstancer;
};

}
