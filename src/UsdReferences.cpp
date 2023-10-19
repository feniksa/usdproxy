#include "UsdReferences.h"
#include "SdfPath.h"

namespace usdproxy
{

UsdReferences::UsdReferences(UsdReferences&& usdReferences)
{
	std::swap(m_usdReferences, usdReferences.m_usdReferences);
}

bool UsdReferences::IsInvalid() const
{
	return !m_usdReferences;
}

bool UsdReferences::AddReference(const std::string& identifier, const SdfPath& primPath)
{
	return m_usdReferences->AddReference(identifier, primPath.Get());
}

UsdReferences::UsdReferences(pxr::UsdReferences&& usdReferences)
: m_usdReferences(std::make_unique<pxr::UsdReferences>(std::move(usdReferences)))
{
}

const pxr::UsdReferences& UsdReferences::Get() const
{
	return *m_usdReferences.get();
}

}

