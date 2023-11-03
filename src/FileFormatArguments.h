#pragma once

#include "usdlib.h"

#include <pxr/usd/sdf/layer.h>

namespace usdproxy
{

class FileFormatArguments
{
public:
	LIBUSDPROXY_API
	FileFormatArguments() = default;

	LIBUSDPROXY_API
	explicit FileFormatArguments(const FileFormatArguments& fileFormatArguments) = default;

	LIBUSDPROXY_API
	explicit FileFormatArguments(const pxr::SdfLayer::FileFormatArguments& fileFormatArguments);

	LIBUSDPROXY_API
	void Insert(const std::string& key, const std::string& value);

	LIBUSDPROXY_API
	const pxr::SdfLayer::FileFormatArguments& Get() const;
private:
	pxr::SdfLayer::FileFormatArguments m_fileFormatArguments;
};

} // namespace


