#include "UsdPrim.h"

#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "UsdReferences.h"

namespace usdproxy
{

const pxr::UsdPrim& UsdPrim::Get() const
{
	return m_usdPrim;
}

UsdPrim::UsdPrim(pxr::UsdPrim&& usdPrim) noexcept
: m_usdPrim(usdPrim)
{
}

UsdStageWeakPtr UsdPrim::GetStage() const
{
	return UsdStageWeakPtr(m_usdPrim.GetStage());
}

SdfPath UsdPrim::GetPath() const
{
	return SdfPath(m_usdPrim.GetPath());
}

bool UsdPrim::GetReferences_AddReference(const std::string& identifier, const SdfPath& primPath)
{
	UsdReferences references(m_usdPrim.GetReferences());
	return references.AddReference(identifier, primPath);
}

}