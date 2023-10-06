#include "UsdStageWeakPtr.h"
#include "UsdStage.h"
#include "UsdStageRefPtr.h"

namespace usdproxy
{

UsdStageWeakPtr::UsdStageWeakPtr(UsdStageRefPtr& usdStageRefPtr)
: m_usdStageWeakPtr(usdStageRefPtr.Get())
{
}

UsdStageWeakPtr::UsdStageWeakPtr(UsdStage& usdStage)
: m_usdStageWeakPtr(usdStage.GetPtr().Get())
{
}


bool UsdStageWeakPtr::HasDefaultPrim() const
{
    return m_usdStageWeakPtr->HasDefaultPrim();
}

}