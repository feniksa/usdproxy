#include "UsdGeomMesh.h"
#include "UsdGeomPrimvar.h"
#include "UsdPrim.h"
#include "VtIntArray.h"
#include "VtVec3fArray.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "TfToken.h"
#include "SdfValueTypeName.h"
#include "UsdAttribute.h"

#include <pxr/base/vt/value.h>
#include <pxr/usd/usdGeom/primvarsAPI.h>
#include <fstream>

namespace usdproxy
{

UsdGeomMesh::UsdGeomMesh()
{
}

UsdGeomMesh::UsdGeomMesh(pxr::UsdGeomMesh&& usdGeomMesh)
: m_usdGeomMesh(usdGeomMesh)
{
}

UsdGeomMesh UsdGeomMesh::Define(const UsdStageWeakPtr& stage, const SdfPath& path)
{
	pxr::UsdGeomMesh usdGeomMesh = pxr::UsdGeomMesh::Define(stage.Get(), path.Get());
	return UsdGeomMesh(std::move(usdGeomMesh));
}

UsdAttribute UsdGeomMesh::CreateFaceVertexIndicesAttr(const VtIntArray& vtIntArray, bool writeSparsely)
{
	const pxr::VtValue value(vtIntArray.Get());
	return m_usdGeomMesh.CreateFaceVertexIndicesAttr(value, writeSparsely);
}

UsdAttribute UsdGeomMesh::CreateFaceVertexCountsAttr(const VtIntArray& vtIntArray, bool writeSparsely)
{
	const pxr::VtValue value(vtIntArray.Get());
	return m_usdGeomMesh.CreateFaceVertexCountsAttr(value, writeSparsely);
}

UsdAttribute UsdGeomMesh::CreatePointsAttr(const VtVec3fArray& vtVec3fArray, bool writeSparsely)
{
	const pxr::VtValue value(vtVec3fArray.Get());
	return m_usdGeomMesh.CreatePointsAttr(value, writeSparsely);
}

UsdAttribute UsdGeomMesh::CreateNormalsAttr(const VtVec3fArray& vtVec3fArray, bool writeSparsely)
{
	const pxr::VtValue value(vtVec3fArray.Get());
	return m_usdGeomMesh.CreateNormalsAttr(value, writeSparsely);
}

bool UsdGeomMesh::SetNormalsInterpolation(UsdGeomTokens token)
{
	return m_usdGeomMesh.SetNormalsInterpolation(token.toPxrToken());
}

bool UsdGeomMesh::SetNormalsInterpolation(const UsdGeomTokens::Token& token)
{
	return SetNormalsInterpolation(UsdGeomTokens(token));
}

UsdGeomPrimvar UsdGeomMesh::CreatePrimvar(const TfToken& token, const SdfValueTypeName& valueType) const
{
	pxr::UsdGeomPrimvarsAPI api(m_usdGeomMesh.GetPrim());
	return { api.CreatePrimvar(token.Get(), valueType.Get()) };
}

UsdGeomPrimvar UsdGeomMesh::CreatePrimvar(const TfToken& token, const SdfValueTypeName::SdfValueTypeNames & valueType) const
{
	return CreatePrimvar(token, SdfValueTypeName(valueType));
}

UsdAttribute UsdGeomMesh::CreateAttribute(const TfToken& token, const SdfValueTypeName& valueType) const
{
	return { m_usdGeomMesh.GetPrim().CreateAttribute(token.Get(), valueType.Get()) };
}

UsdPrim UsdGeomMesh::GetPrim() const
{
	return m_usdGeomMesh.GetPrim();
}

SdfPath UsdGeomMesh::GetPath() const
{
	return m_usdGeomMesh.GetPath();
}

}