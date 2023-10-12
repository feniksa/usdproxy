#include "UsdStage.h"

#include "SdfPath.h"
#include "UsdPrim.h"
#include "UsdStageRefPtr.h"
#include "SdfLayerHandle.h"

#include <pxr/usd/usd/stage.h>

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

UsdStage::UsdStage(pxr::UsdStageRefPtr &&usdStageRefPtr)
	: m_usdStageRefPtr(std::move(usdStageRefPtr))
{
}

UsdStage::UsdStage(pxr::UsdStageRefPtr usdStageRefPtr)
	: m_usdStageRefPtr(usdStageRefPtr)
{
}

UsdStageRefPtr UsdStage::Open(const std::string &filePath, InitialLoadSet load)
{
	pxr::UsdStageRefPtr stagePtr = pxr::UsdStage::Open(filePath, convert(load));
	return stagePtr;
}

UsdStageRefPtr UsdStage::CreateInMemory()
{
	return {pxr::UsdStage::CreateInMemory()};
}

SdfLayerHandle UsdStage::GetRootLayer()
{
	return {m_usdStageRefPtr->GetRootLayer()};
}

const pxr::UsdStageRefPtr &UsdStage::Get() const
{
	return m_usdStageRefPtr;
}

void UsdStage::SetDefaultPrim(const UsdPrim &prim)
{
	m_usdStageRefPtr->SetDefaultPrim(prim.Get());
}

UsdPrim UsdStage::OverridePrim(const SdfPath &path)
{
	return {m_usdStageRefPtr->OverridePrim(path.Get())};
}

UsdPrim UsdStage::GetDefaultPrim() const
{
	return { m_usdStageRefPtr->GetDefaultPrim() };
}

bool UsdStage::RemovePrim(const SdfPath& path)
{
	return m_usdStageRefPtr->RemovePrim(path.Get());
}
}