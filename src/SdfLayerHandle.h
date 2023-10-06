#pragma once

#include "usdlib.h"

#include <pxr/usd/sdf/layer.h>

namespace usdproxy
{

class SdfLayerHandle
{
public:
    LIBUSDPROXY_API
    SdfLayerHandle() = default;

    LIBUSDPROXY_API
    SdfLayerHandle(pxr::SdfLayerHandle handle);

    LIBUSDPROXY_API
    bool Export(const std::string& filePath);

private:
    pxr::SdfLayerHandle m_sdfLayerHandle;
};

}