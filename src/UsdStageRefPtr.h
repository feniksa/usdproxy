#pragma once

#include "usdlib.h"
#include "SdfLayerHandle.h"
#include "UsdStageRefPtr.h"
#include <pxr/usd/usd/stage.h>

namespace usdproxy
{

class UsdStageRefPtr {
public:
    LIBUSDPROXY_API UsdStageRefPtr(pxr::UsdStageRefPtr ptr = pxr::UsdStageRefPtr());
    LIBUSDPROXY_API bool IsOpened() const;

    LIBUSDPROXY_API SdfLayerHandle GetRootLayer() const;
    LIBUSDPROXY_API void Traverse() const;
private:
    pxr::UsdStageRefPtr m_ptr;
};

}