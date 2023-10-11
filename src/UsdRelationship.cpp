#include "UsdRelationship.h"
#include "SdfPath.h"

namespace usdproxy
{

UsdRelationship::UsdRelationship(pxr::UsdRelationship&& usdRelationship)
: m_usdRelationShip(std::move(usdRelationship))
{
}

bool UsdRelationship::AddTarget(const SdfPath& path)
{
	return m_usdRelationShip.AddTarget(path.Get());
}

const pxr::UsdRelationship& UsdRelationship::Get() const
{
	return m_usdRelationShip;
}

}