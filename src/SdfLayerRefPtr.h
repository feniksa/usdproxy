#pragma once

#include "usdlib.h"
#include "FileFormatArguments.h"
#include <pxr/usd/sdf/layer.h>

namespace usdproxy
{

class SdfLayerRefPtr
{
public:
	LIBUSDPROXY_API
	SdfLayerRefPtr() = default;

	LIBUSDPROXY_API
	SdfLayerRefPtr(const SdfLayerRefPtr& sdfLayerRefPtr) = default;

	LIBUSDPROXY_API
	SdfLayerRefPtr(const pxr::SdfLayerRefPtr& sdfLayerRefPtr);

	LIBUSDPROXY_API
	const pxr::SdfLayerRefPtr& Get() const;

	LIBUSDPROXY_API
	bool Save(bool force = false) const;

	LIBUSDPROXY_API
	bool Export (const std::string &filename, const std::string& comment = std::string(),
				 const FileFormatArguments &args = FileFormatArguments()) const;

	LIBUSDPROXY_API
	std::string ExportToString() const;

	LIBUSDPROXY_API
	void Clear();

	LIBUSDPROXY_API
	bool IsEmpty() const;

private:
	pxr::SdfLayerRefPtr m_sdfLayerRefPtr;
};

}