#include "UsdStage.h"

#include <pxr/usd/usd/stage.h>

#include "SdfPath.h"
#include "UsdPrim.h"
#include "UsdStageRefPtr.h"
#include "SdfLayerHandle.h"
#include "SdfLayerHandleVector.h"
#include "SdfLayerRefPtr.h"

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

UsdStage::UsdStage(const pxr::UsdStageRefPtr& usdStageRefPtr)
: m_usdStageRefPtr(usdStageRefPtr)
{
}

UsdStageRefPtr UsdStage::Open(const std::string &filePath, InitialLoadSet load)
{
	pxr::UsdStageRefPtr stagePtr = pxr::UsdStage::Open(filePath, convert(load));
	return stagePtr;
}

UsdStage UsdStage::CreateNew(const std::string& identifier, InitialLoadSet load)
{
	return pxr::UsdStage::CreateNew(identifier, convert(load));
}

UsdStage UsdStage::CreateInMemory()
{
	return pxr::UsdStage::CreateInMemory();
}

UsdStage UsdStage::CreateInMemory(const std::string &identifier, usdproxy::UsdStage::InitialLoadSet load)
{
	return pxr::UsdStage::CreateInMemory(identifier, convert(load));
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

UsdStage::UsdStage(const UsdStage& usdStage)
: m_usdStageRefPtr(usdStage.m_usdStageRefPtr)
{
}

std::string UsdStage::ExportToString() const
{
	std::string result;
	m_usdStageRefPtr->ExportToString(&result);

	return result;
}

SdfLayerHandleVector UsdStage::GetLayerStack(bool includeSessionLayers) const
{
	return SdfLayerHandleVector(m_usdStageRefPtr->GetLayerStack(includeSessionLayers));
}

SdfLayerRefPtr UsdStage::Flatten(bool addSourceFileComment)
{
	return SdfLayerRefPtr(m_usdStageRefPtr->Flatten(addSourceFileComment));
}

}