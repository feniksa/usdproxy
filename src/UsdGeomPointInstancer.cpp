#include "UsdGeomPointInstancer.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "UsdRelationship.h"
#include "VtIntArray.h"
#include "VtVec3fArray.h"
#include "VtQuathArray.h"
#include "UsdAttribute.h"
#include "VtVec3dArray.h"

namespace usdproxy
{

UsdGeomPointInstancer::UsdGeomPointInstancer(const pxr::UsdGeomPointInstancer& usdGeomPointInstancer)
: m_usdGeomPointInstancer(usdGeomPointInstancer)
{
}

UsdGeomPointInstancer UsdGeomPointInstancer::Define(const UsdStageWeakPtr &stage, const SdfPath &path)
{
	return { pxr::UsdGeomPointInstancer::Define(stage.Get(), path.Get()) };
}

UsdRelationship UsdGeomPointInstancer::GetPrototypesRel()
{
	return { m_usdGeomPointInstancer.GetPrototypesRel() };
}

const pxr::UsdGeomPointInstancer& UsdGeomPointInstancer::Get() const
{
	return m_usdGeomPointInstancer;
}
UsdAttribute UsdGeomPointInstancer::CreateProtoIndicesAttr(const VtIntArray& value)
{
	const pxr::VtValue val(value.Get());
	return { m_usdGeomPointInstancer.CreateProtoIndicesAttr(val) };
}

UsdAttribute UsdGeomPointInstancer::CreatePositionsAttr(const VtVec3fArray& value)
{
	const pxr::VtValue val(value.Get());
	return { m_usdGeomPointInstancer.CreatePositionsAttr(val) };
}

UsdAttribute UsdGeomPointInstancer::CreatePositionsAttr(const VtVec3dArray& value)
{
	const pxr::VtValue val(value.Get());
	return { m_usdGeomPointInstancer.CreatePositionsAttr(val) };
}

UsdAttribute UsdGeomPointInstancer::CreateOrientationsAttr(const VtQuathArray& value)
{
	const pxr::VtValue val(value.Get());
	return { m_usdGeomPointInstancer.CreateOrientationsAttr(val) };
}

}
