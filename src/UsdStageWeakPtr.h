#pragma once

#include "usdlib.h"
#include "UsdPrim.h"
#include <pxr/usd/usd/stage.h>

namespace usdproxy
{

class UsdStageRefPtr;
class UsdStage;
class SdfPath;

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

	LIBUSDPROXY_API
	UsdPrim GetPrimAtPath(const SdfPath& path);

	LIBUSDPROXY_API
	const pxr::UsdStageWeakPtr& Get() const;

private:
    pxr::UsdStageWeakPtr m_usdStageWeakPtr;
};
}