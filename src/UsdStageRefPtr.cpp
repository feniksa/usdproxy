#include "UsdStageRefPtr.h"
#include "UsdPrim.h"

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


const pxr::UsdStageRefPtr& UsdStageRefPtr::Get() const
{
    return m_ptr;
}

void UsdStageRefPtr::SetDefaultPrim(const UsdPrim& prim)
{
	m_ptr->SetDefaultPrim(prim.Get());
}

}