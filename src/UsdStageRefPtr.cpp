#include "UsdStageRefPtr.h"

namespace usdproxy
{

UsdStageRefPtr::UsdStageRefPtr(pxr::UsdStageRefPtr ptr)
        : m_ptr(ptr)
{
}

SdfLayerHandle UsdStageRefPtr::GetRootLayer() const
{
    return SdfLayerHandle(m_ptr->GetRootLayer());
}

void UsdStageRefPtr::Traverse() const
{
    //m_ptr->Traverse();
}

bool UsdStageRefPtr::IsOpened() const
{
    return m_ptr != nullptr;
}


pxr::UsdStageRefPtr& UsdStageRefPtr::Get()
{
    return m_ptr;
}

}