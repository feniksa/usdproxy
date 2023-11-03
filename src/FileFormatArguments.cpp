#include "FileFormatArguments.h"

namespace usdproxy
{

FileFormatArguments::FileFormatArguments(const pxr::SdfLayer::FileFormatArguments& fileFormatArguments)
: m_fileFormatArguments(fileFormatArguments)
{
}

void FileFormatArguments::Insert(const std::string& key, const std::string& value)
{
	m_fileFormatArguments.insert(std::make_pair(key, value));
}

const pxr::SdfLayer::FileFormatArguments& FileFormatArguments::Get() const
{
	return m_fileFormatArguments;
}

}

