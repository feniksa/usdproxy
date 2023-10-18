#include "SdfPath.h"

namespace usdproxy
{

SdfPath::SdfPath(const SdfPath& sdfPath)
: m_sdfPath(sdfPath.m_sdfPath)
{
}

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

SdfPath SdfPath::AppendElementString(const std::string& element)
{
	return m_sdfPath.AppendElementString(element);
}

std::string SdfPath::GetAsString() const
{
	return m_sdfPath.GetAsString();
}

bool IsValidIdentifier(const std::string& name)
{
	return pxr::SdfPath::IsValidIdentifier(name);
}

}