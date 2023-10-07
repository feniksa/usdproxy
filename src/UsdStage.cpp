#include "UsdStage.h"

#include <pxr/usd/usd/stage.h>

PXR_NAMESPACE_USING_DIRECTIVE

namespace
{

pxr::UsdStage::InitialLoadSet convert(usdproxy::UsdStage::InitialLoadSet load)
{
    switch(load){
        case usdproxy::UsdStage::LoadAll:
            return pxr::UsdStage::LoadAll;
        case usdproxy::UsdStage::LoadNone:
            return pxr::UsdStage::LoadNone;
        default:
            return pxr::UsdStage::LoadAll;
    }
}

}

namespace usdproxy
{

UsdStage::UsdStage(UsdStageRefPtr usdStageRefPtr) : m_usdStageRefPtr(usdStageRefPtr)
{
}

UsdStageRefPtr UsdStage::Open(const std::string& filePath, InitialLoadSet load)
{
    pxr::UsdStageRefPtr stagePtr = pxr::UsdStage::Open(filePath, convert(load));
    return stagePtr;
}

UsdStageRefPtr UsdStage::CreateInMemory()
{
    pxr::UsdStageRefPtr stagePtr = pxr::UsdStage::CreateInMemory();
    return UsdStageRefPtr(stagePtr);
}

SdfLayerHandle UsdStage::GetRootLayer()
{
    return SdfLayerHandle(m_usdStageRefPtr.GetRootLayer());
}

UsdStageRefPtr& UsdStage::GetPtr()
{
    return m_usdStageRefPtr;
}

void UsdStage::SetDefaultPrim(const UsdPrim& prim)
{
	m_usdStageRefPtr.SetDefaultPrim(prim);
}

}