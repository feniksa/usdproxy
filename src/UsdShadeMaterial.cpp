#include "UsdShadeMaterial.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "UsdShadeOutput.h"
#include "UsdPrim.h"
#include "pxr/usd/usdShade/materialBindingAPI.h"

namespace usdproxy
{

UsdShadeMaterial::UsdShadeMaterial()
{
}

UsdShadeMaterial::UsdShadeMaterial(const pxr::UsdShadeMaterial& usdShadeMaterial)
: m_usdShadeMaterial(usdShadeMaterial)
{
}

UsdShadeMaterial UsdShadeMaterial::Define(const UsdStageWeakPtr& stage, const SdfPath& path)
{
	return UsdShadeMaterial(pxr::UsdShadeMaterial::Define(stage.Get(), path.Get()));
}

UsdShadeOutput UsdShadeMaterial::CreateSurfaceOutput()
{
	return UsdShadeOutput(m_usdShadeMaterial.CreateSurfaceOutput());
}

SdfPath UsdShadeMaterial::GetPath() const
{
	return SdfPath(m_usdShadeMaterial.GetPath());
}


void UsdShadeMaterial::Bind(const UsdPrim& prim)
{
	//m_usdShadeMaterial.
	pxr::UsdShadeMaterialBindingAPI bindingApi(prim.Get());
	bindingApi.Bind(m_usdShadeMaterial);
}

}