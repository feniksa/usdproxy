#include "UsdStageWeakPtr.h"
#include "UsdStage.h"
#include "UsdStageRefPtr.h"
#include "SdfPath.h"
#include "UsdPrim.h"

namespace usdproxy
{

UsdStageWeakPtr::UsdStageWeakPtr(UsdStageRefPtr &usdStageRefPtr)
	: m_usdStageWeakPtr(usdStageRefPtr.Get())
{
}

UsdStageWeakPtr::UsdStageWeakPtr(UsdStage &usdStage)
	: m_usdStageWeakPtr(usdStage.GetPtr().Get())
{
}

UsdStageWeakPtr::UsdStageWeakPtr(pxr::UsdStageWeakPtr&& usdStageWeakPtr)
: m_usdStageWeakPtr(std::move(usdStageWeakPtr))
{
}


UsdStageWeakPtr::UsdStageWeakPtr(UsdStageWeakPtr&& other) noexcept
: m_usdStageWeakPtr(std::move(other.m_usdStageWeakPtr))
{
}

UsdStageWeakPtr& UsdStageWeakPtr::operator=(UsdStageWeakPtr&& other) noexcept
{
	if (this == &other)
		return *this;

	std::swap(m_usdStageWeakPtr, other.m_usdStageWeakPtr);
	other.m_usdStageWeakPtr.Reset();

	return *this;
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

}