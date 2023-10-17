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
    UsdStage() = default;

	LIBUSDPROXY_API
	UsdStage(const pxr::UsdStageRefPtr& usdStageRefPtr);

    LIBUSDPROXY_API
    UsdStage(const UsdStage& usdStage);

    LIBUSDPROXY_API
    static
    UsdStageRefPtr Open(const std::string& filePath, InitialLoadSet load = LoadAll);

    LIBUSDPROXY_API
    static
    UsdStage CreateInMemory();

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
	std::string ExportToString() const;

	LIBUSDPROXY_API
	const pxr::UsdStageRefPtr& Get() const;
private:
    pxr::UsdStageRefPtr m_usdStageRefPtr;
};

}