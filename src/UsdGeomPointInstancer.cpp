#include "UsdGeomPointInstancer.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "UsdRelationship.h"

namespace usdproxy
{

UsdGeomPointInstancer::UsdGeomPointInstancer(pxr::UsdGeomPointInstancer&& usdGeomPointInstancer)
: m_usdGeomPointInstancer(std::move(usdGeomPointInstancer))
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

}
