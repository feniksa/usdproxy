#include "UsdStage.h"

#include <pxr/usd/usd/stage.h>

PXR_NAMESPACE_USING_DIRECTIVE

namespace usdproxy
{

inline pxr::UsdStage::InitialLoadSet convert(UsdStage::InitialLoadSet load)
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

}