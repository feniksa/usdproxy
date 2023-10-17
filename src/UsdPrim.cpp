#include "UsdPrim.h"

#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "UsdReferences.h"

namespace usdproxy
{

UsdPrim::UsdPrim(const UsdPrim& usdPrim)
: m_usdPrim(usdPrim.m_usdPrim)
{
}

UsdPrim::UsdPrim(const pxr::UsdPrim& usdPrim)
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

const pxr::UsdPrim& UsdPrim::Get() const
{
	return m_usdPrim;
}

bool UsdPrim::GetReferences_AddReference(const std::string& identifier, const SdfPath& primPath)
{
	UsdReferences references(m_usdPrim.GetReferences());
	return references.AddReference(identifier, primPath);
}



}