#include "UsdStageWeakPtr.h"
#include "UsdStage.h"
#include "UsdStageRefPtr.h"
#include "SdfPath.h"
#include "UsdPrim.h"

namespace usdproxy
{

UsdStageWeakPtr::UsdStageWeakPtr(const UsdStageRefPtr& usdStageRefPtr)
: m_usdStageWeakPtr(usdStageRefPtr.Get())
{
}

UsdStageWeakPtr::UsdStageWeakPtr(const UsdStageWeakPtr& usdStageWeakPtr)
: m_usdStageWeakPtr(usdStageWeakPtr.m_usdStageWeakPtr)
{
}

UsdStageWeakPtr::UsdStageWeakPtr(const UsdStage &usdStage)
: m_usdStageWeakPtr(usdStage.Get())
{
}

UsdStageWeakPtr::UsdStageWeakPtr(const pxr::UsdStageWeakPtr& usdStageWeakPtr)
: m_usdStageWeakPtr(usdStageWeakPtr)
{
}

bool UsdStageWeakPtr::HasDefaultPrim() const
{
	return m_usdStageWeakPtr->HasDefaultPrim();
}

const pxr::UsdStageWeakPtr &UsdStageWeakPtr::Get() const
{
	return m_usdStageWeakPtr;
}

UsdPrim UsdStageWeakPtr::GetPrimAtPath(const usdproxy::SdfPath &path)
{
	return UsdPrim(m_usdStageWeakPtr->GetPrimAtPath(path.Get()));
}

UsdPrim UsdStageWeakPtr::DefinePrim(const SdfPath& path)
{
	return m_usdStageWeakPtr->DefinePrim(path.Get());
}

void UsdStageWeakPtr::SetDefaultPrim(const UsdPrim& usdPrim)
{
	m_usdStageWeakPtr->SetDefaultPrim(usdPrim.Get());
}

std::string UsdStageWeakPtr::ExportAsString() const
{
	std::string result;

	m_usdStageWeakPtr->ExportToString(&result);

	return result;
}

}