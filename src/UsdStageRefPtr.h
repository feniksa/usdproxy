#pragma once

#include "usdlib.h"
#include "SdfLayerHandle.h"
#include <pxr/usd/usd/stage.h>

namespace usdproxy
{

class UsdPrim;

class UsdStageRefPtr {
public:
    LIBUSDPROXY_API
    UsdStageRefPtr(pxr::UsdStageRefPtr ptr = pxr::UsdStageRefPtr());

    LIBUSDPROXY_API
    bool IsOpened() const;

    LIBUSDPROXY_API
    SdfLayerHandle GetRootLayer() const;

    LIBUSDPROXY_API
    void Traverse() const;

    LIBUSDPROXY_API
    const pxr::UsdStageRefPtr& Get() const;

	LIBUSDPROXY_API
	void SetDefaultPrim(const UsdPrim& prim);
private:
    pxr::UsdStageRefPtr m_ptr;
};

}