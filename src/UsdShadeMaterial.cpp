#include "UsdShadeMaterial.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"

namespace usdproxy
{

UsdShadeMaterial::UsdShadeMaterial()
{
}

UsdShadeMaterial::UsdShadeMaterial(pxr::UsdShadeMaterial&& usdShadeMaterial)
: m_usdShadeMaterial(usdShadeMaterial)
{
}

UsdShadeMaterial UsdShadeMaterial::Define(const UsdStageWeakPtr& stage, const SdfPath& path)
{
	return UsdShadeMaterial(pxr::UsdShadeMaterial::Define(stage.Get(), path.Get()));
}

}