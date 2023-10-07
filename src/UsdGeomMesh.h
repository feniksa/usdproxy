#pragma once

#include "usdlib.h"
#include <pxr/usd/usdGeom/mesh.h>

namespace usdproxy
{

class VtIntArray;
class VtVec3fArray;

class UsdGeomMesh
{
public:
	LIBUSDPROXY_API
	UsdGeomMesh();

	LIBUSDPROXY_API
	void CreateFaceVertexIndicesAttr(const VtIntArray& vtIntArray, bool writeSparsely = false);

	LIBUSDPROXY_API
	void CreateFaceVertexCountsAttr(const VtIntArray& vtIntArray, bool writeSparsely = false);

	LIBUSDPROXY_API
	void CreatePointsAttr(const VtVec3fArray& vtVec3fArray, bool writeSparsely = false);
private:
	pxr::UsdGeomMesh m_usdGeomMesh;
};

}