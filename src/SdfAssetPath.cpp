#include "SdfAssetPath.h"

namespace usdproxy
{

const pxr::SdfAssetPath& SdfAssetPath::Get() const
{
	return m_sdfAssetPath;
}


SdfAssetPath::SdfAssetPath(const std::string& path)
: m_sdfAssetPath(path)
{
}

}