#include "SdfLayerHandle.h"

namespace usdproxy
{

SdfLayerHandle::SdfLayerHandle(pxr::SdfLayerHandle handle)
: m_sdfLayerHandle(handle)
{
}

bool SdfLayerHandle::Export(const std::string &filePath)
{
    return m_sdfLayerHandle->Export(filePath);
}

}