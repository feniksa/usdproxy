#include "UsdGeomMesh.h"
#include "VtIntArray.h"
#include "VtVec3fArray.h"
#include <pxr/base/vt/value.h>
#include <pxr/base/vt/types.h>

namespace usdproxy
{

UsdGeomMesh::UsdGeomMesh()
{
}

void UsdGeomMesh::CreateFaceVertexIndicesAttr(const VtIntArray& vtIntArray, bool writeSparsely)
{
	const pxr::VtValue value(vtIntArray.Get());
	m_usdGeomMesh.CreateFaceVertexIndicesAttr(value, writeSparsely);
}


void UsdGeomMesh::CreateFaceVertexCountsAttr(const VtIntArray& vtIntArray, bool writeSparsely)
{
	const pxr::VtValue value(vtIntArray.Get());
	m_usdGeomMesh.CreateFaceVertexCountsAttr(value, writeSparsely);
}

void UsdGeomMesh::CreatePointsAttr(const VtVec3fArray& vtVec3fArray, bool writeSparsely)
{
	const pxr::VtValue value(vtVec3fArray.Get());
	m_usdGeomMesh.CreatePointsAttr(value, writeSparsely);
}

}