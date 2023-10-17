#pragma once

#include "usdlib.h"
#include "UsdGeomTokens.h"
#include "SdfValueTypeName.h"
#include <pxr/usd/usdGeom/mesh.h>

namespace usdproxy
{

class VtIntArray;
class VtVec3fArray;
class UsdStageWeakPtr;
class SdfPath;
class UsdPrim;
class UsdAttribute;
class UsdPrim;
class TfToken;
class UsdGeomPrimvar;

class UsdGeomMesh
{
public:
	LIBUSDPROXY_API
	UsdGeomMesh();

	LIBUSDPROXY_API
	UsdGeomMesh(const pxr::UsdGeomMesh& usdGeomMesh);

	LIBUSDPROXY_API
	static
	UsdGeomMesh Define(const UsdStageWeakPtr& stage, const SdfPath& path);

	LIBUSDPROXY_API
	UsdAttribute CreateFaceVertexIndicesAttr(const VtIntArray& vtIntArray, bool writeSparsely = false);

	LIBUSDPROXY_API
	UsdAttribute CreateFaceVertexCountsAttr(const VtIntArray& vtIntArray, bool writeSparsely = false);

	LIBUSDPROXY_API
	UsdAttribute CreatePointsAttr(const VtVec3fArray& vtVec3fArray, bool writeSparsely = false);

	LIBUSDPROXY_API
	UsdAttribute CreateNormalsAttr(const VtVec3fArray& vtVec3fArray, bool writeSparsely = false);

	LIBUSDPROXY_API
	bool SetNormalsInterpolation(UsdGeomTokens token);

	LIBUSDPROXY_API
	bool SetNormalsInterpolation(const UsdGeomTokens::Token& token);

	LIBUSDPROXY_API
	UsdAttribute CreateAttribute(const TfToken& token, const SdfValueTypeName& valueType) const;

	LIBUSDPROXY_API
	UsdGeomPrimvar CreatePrimvar(const TfToken& token, const SdfValueTypeName& valueType) const;

	LIBUSDPROXY_API
	UsdGeomPrimvar CreatePrimvar(const TfToken& token, const SdfValueTypeName::SdfValueTypeNames & valueType) const; // alias

	LIBUSDPROXY_API
	UsdPrim GetPrim() const;

	LIBUSDPROXY_API
	SdfPath GetPath() const;

private:
	pxr::UsdGeomMesh m_usdGeomMesh;
};

}