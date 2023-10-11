#pragma once

#include "usdlib.h"
#include "UsdGeomTokens.h"
#include "UsdGeomPrimvar.h"
#include "UsdPrim.h"
#include <pxr/usd/usdGeom/mesh.h>

namespace usdproxy
{

class VtIntArray;
class VtVec3fArray;
class UsdStageWeakPtr;
class SdfPath;

class UsdGeomMesh
{
public:
	LIBUSDPROXY_API
	UsdGeomMesh();

	LIBUSDPROXY_API
	explicit UsdGeomMesh(pxr::UsdGeomMesh&& usdGeomMesh);

	LIBUSDPROXY_API
	static
	UsdGeomMesh Define(const UsdStageWeakPtr& stage, const SdfPath& path);

	LIBUSDPROXY_API
	void CreateFaceVertexIndicesAttr(const VtIntArray& vtIntArray, bool writeSparsely = false);

	LIBUSDPROXY_API
	void CreateFaceVertexCountsAttr(const VtIntArray& vtIntArray, bool writeSparsely = false);

	LIBUSDPROXY_API
	void CreatePointsAttr(const VtVec3fArray& vtVec3fArray, bool writeSparsely = false);

	LIBUSDPROXY_API
	void CreateNormalsAttr(const VtVec3fArray& vtVec3fArray, bool writeSparsely = false);

	LIBUSDPROXY_API
	bool SetNormalsInterpolation(UsdGeomTokens token);

	LIBUSDPROXY_API
	bool SetNormalsInterpolation(const UsdGeomTokens::Token& token);

	//LIBUSDPROXY_API
	//UsdGeomPrimvar CreatePrimVar();

	LIBUSDPROXY_API
	UsdPrim GetPrim() const;

private:
	pxr::UsdGeomMesh m_usdGeomMesh;
};

}