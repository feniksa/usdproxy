#include "SdfLayerRefPtr.h"

namespace usdproxy
{

SdfLayerRefPtr::SdfLayerRefPtr(const pxr::SdfLayerRefPtr& sdfLayerRefPtr)
: m_sdfLayerRefPtr(sdfLayerRefPtr)
{
}

const pxr::SdfLayerRefPtr& SdfLayerRefPtr::Get() const
{
	return m_sdfLayerRefPtr;
}

bool SdfLayerRefPtr::Save(bool force) const
{
	return m_sdfLayerRefPtr->Save(force);
}

bool SdfLayerRefPtr::Export(const std::string &filename, const std::string& comment, const FileFormatArguments &args) const
{
	return m_sdfLayerRefPtr->Export(filename, comment, args.Get());
}

std::string SdfLayerRefPtr::ExportToString() const
{
	std::string result;

	return m_sdfLayerRefPtr->ExportToString(&result) ? result : std::string();
}

void SdfLayerRefPtr::Clear()
{
	m_sdfLayerRefPtr->Clear();
}

bool SdfLayerRefPtr::IsEmpty() const
{
	return m_sdfLayerRefPtr->IsEmpty();
}
}