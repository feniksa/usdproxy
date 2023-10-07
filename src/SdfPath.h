#pragma once

#include "usdlib.h"
#include <pxr/usd/sdf/path.h>

namespace usdproxy
{

class SdfPath
{
public:
    LIBUSDPROXY_API
    SdfPath() = default;

    LIBUSDPROXY_API
    SdfPath(const SdfPath&) = default;

    LIBUSDPROXY_API
    SdfPath(SdfPath&&) noexcept = default;

    LIBUSDPROXY_API
    explicit SdfPath(pxr::SdfPath& path);

    LIBUSDPROXY_API
    explicit SdfPath(const std::string& path);

    LIBUSDPROXY_API
    SdfPath& operator=(const SdfPath&) = default;

    LIBUSDPROXY_API
    SdfPath& operator=(SdfPath&&) noexcept = default;

	LIBUSDPROXY_API
	const pxr::SdfPath& Get() const;

private:
    pxr::SdfPath m_sdfPath;
};

} // namespace