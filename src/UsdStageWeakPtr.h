#pragma once

#include "usdlib.h"
#include <pxr/usd/usd/stage.h>

namespace usdproxy
{

class UsdStageRefPtr;
class UsdStage;
class SdfPath;
class UsdPrim;

class UsdStageWeakPtr
{
public:
    LIBUSDPROXY_API
    UsdStageWeakPtr() = default;

    LIBUSDPROXY_API
    UsdStageWeakPtr(const UsdStageWeakPtr& usdStageWeakPtr);

	LIBUSDPROXY_API
	UsdStageWeakPtr(const pxr::UsdStageWeakPtr& usdStageWeakPtr);

    LIBUSDPROXY_API
    UsdStageWeakPtr(const UsdStage& usdStageRefPtr);

    LIBUSDPROXY_API
    UsdStageWeakPtr(const UsdStageRefPtr& usdStageRefPtr);

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