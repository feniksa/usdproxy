#pragma once

#include "usdlib.h"
#include "UsdStageRefPtr.h"
#include "SdfLayerHandle.h"
#include <pxr/usd/usd/stage.h>
#include <string>

namespace usdproxy
{

class UsdPrim;

class UsdStage
{
public:
    enum InitialLoadSet
    {
        LoadAll, ///< Load all loadable prims
        LoadNone ///< Load no loadable prims
    };

    LIBUSDPROXY_API
    UsdStage(UsdStageRefPtr usdStageRefPtr = UsdStageRefPtr());

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
    UsdStageRefPtr& GetPtr();

private:
    UsdStageRefPtr m_usdStageRefPtr;
};

}