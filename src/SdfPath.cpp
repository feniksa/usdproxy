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

SdfPath::SdfPath(const std::string& path)
: m_sdfPath(path)
{
}

const pxr::SdfPath& SdfPath::Get() const
{
	return m_sdfPath;
}

SdfPath SdfPath::AppendElementString(const std::string& element)
{
	return SdfPath(m_sdfPath.AppendElementString(element));
}

std::string SdfPath::GetAsString() const
{
	return m_sdfPath.GetAsString();
}

const std::string& SdfPath::GetString() const
{
	return m_sdfPath.GetString();
}

bool SdfPath::IsValidIdentifier(const std::string& name)
{
	return pxr::SdfPath::IsValidIdentifier(name);
}

SdfPath SdfPath::AppendPath(const SdfPath& newSuffix) const
{
	return SdfPath(m_sdfPath.AppendPath(newSuffix.m_sdfPath));
}


bool SdfPath::IsEmpty() const
{
	return m_sdfPath.IsEmpty();
}

}