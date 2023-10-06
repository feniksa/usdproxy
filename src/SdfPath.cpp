#include "SdfPath.h"

namespace usdproxy
{

SdfPath::SdfPath(pxr::SdfPath& path)
: m_sdfPath(path)
{
}

SdfPath::SdfPath(const std::string& path) : m_sdfPath(path)
{
}

}


