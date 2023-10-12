#pragma once

#include "usdlib.h"
#include <pxr/usd/usd/stage.h>
#include <string>

namespace usdproxy
{

class UsdStageRefPtr;
class UsdPrim;
class SdfPath;
class SdfLayerHandle;

class UsdStage
{
public:
    enum InitialLoadSet
    {
        LoadAll, ///< Load all loadable prims
        LoadNone ///< Load no loadable prims
    };

    LIBUSDPROXY_API
    UsdStage(pxr::UsdStageRefPtr usdStageRefPtr = pxr::UsdStageRefPtr());

	LIBUSDPROXY_API
	UsdStage(pxr::UsdStageRefPtr&& usdStageRefPtr);

    LIBUSDPROXY_API
    UsdStage(const UsdStage&) = default;

    LIBUSDPROXY_API
    UsdStage(UsdStage&&) noexcept = default;

    LIBUSDPROXY_API
    static
    UsdStageRefPtr Open(const std::string& filePath, InitialLoadSet load = LoadAll);

    LIBUSDPROXY_API
    static
    UsdStageRefPtr CreateInMemory();

    LIBUSDPROXY_API
    SdfLayerHandle GetRootLayer();

	LIBUSDPROXY_API
	void SetDefaultPrim(const UsdPrim& prim);

	LIBUSDPROXY_API
	UsdPrim GetDefaultPrim() const;

	LIBUSDPROXY_API
	UsdPrim OverridePrim(const SdfPath& path);

	LIBUSDPROXY_API
	bool RemovePrim(const SdfPath& path);

	LIBUSDPROXY_API
	const pxr::UsdStageRefPtr& Get() const;
private:
    pxr::UsdStageRefPtr m_usdStageRefPtr;
};

}