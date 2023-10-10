#pragma once

#include <pxr/usd/sdf/assetPath.h>
#include "usdlib.h"

namespace usdproxy
{
class SdfAssetPath
{
public:
	LIBUSDPROXY_API
	SdfAssetPath() = default;

	LIBUSDPROXY_API
	SdfAssetPath(const std::string& path);

	LIBUSDPROXY_API
	const pxr::SdfAssetPath& Get() const;

private:
	pxr::SdfAssetPath m_sdfAssetPath;
};

}

