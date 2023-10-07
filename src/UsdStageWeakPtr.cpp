#include "UsdStageWeakPtr.h"
#include "UsdStage.h"
#include "UsdStageRefPtr.h"
#include "SdfPath.h"

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