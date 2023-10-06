#pragma once

#include "usdlib.h"
#include "UsdStageRefPtr.h"
#include <pxr/usd/usd/stage.h>
#include <string>

namespace usdproxy
{

class UsdStage
{
public:
    enum InitialLoadSet
    {
        LoadAll, ///< Load all loadable prims
        LoadNone ///< Load no loadable prims
    };

    LIBUSDPROXY_API static UsdStageRefPtr Open(const std::string& filePath, InitialLoadSet load = LoadAll);
    LIBUSDPROXY_API static UsdStageRefPtr CreateInMemory();
private:
};

}