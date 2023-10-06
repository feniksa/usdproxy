#pragma once

#include "usdlib.h"
#include <pxr/usd/usd/stage.h>

namespace usdproxy
{

class UsdStageRefPtr;
class UsdStage;

class UsdStageWeakPtr
{
public:
    LIBUSDPROXY_API
    UsdStageWeakPtr() = default;

    LIBUSDPROXY_API
    UsdStageWeakPtr(const UsdStageWeakPtr&) = default;

    LIBUSDPROXY_API
    UsdStageWeakPtr(UsdStageWeakPtr&&) noexcept  = default;

    LIBUSDPROXY_API
    UsdStageWeakPtr(UsdStage& usdStageRefPtr);

    LIBUSDPROXY_API
    UsdStageWeakPtr(UsdStageRefPtr& usdStageRefPtr);

    LIBUSDPROXY_API
    bool HasDefaultPrim() const;
private:
    pxr::UsdStageWeakPtr m_usdStageWeakPtr;
};
}