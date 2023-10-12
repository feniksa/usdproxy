#include "SdfPath.h"

namespace usdproxy
{

SdfPath::SdfPath(const pxr::SdfPath& path)
: m_sdfPath(path)
{
}

SdfPath::SdfPath(const std::string& path) : m_sdfPath(path)
{
}

const pxr::SdfPath& SdfPath::Get() const
{
	return m_sdfPath;
}

SdfPath SdfPath::AppendElementString(const std::string& s)
{
	return SdfPath(m_sdfPath.AppendElementString(s));
}

std::string SdfPath::GetAsString() const
{
	return m_sdfPath.GetAsString();
}

}


