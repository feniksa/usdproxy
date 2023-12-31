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
    explicit SdfPath(const SdfPath& sdfPath);

    LIBUSDPROXY_API
    explicit SdfPath(const pxr::SdfPath& path);

    LIBUSDPROXY_API
    explicit SdfPath(const std::string& path);

	LIBUSDPROXY_API
	const pxr::SdfPath& Get() const;

	LIBUSDPROXY_API
	SdfPath AppendPath(const SdfPath& newSuffix) const;

	LIBUSDPROXY_API
	SdfPath AppendElementString(const std::string& element);

	LIBUSDPROXY_API
	std::string GetAsString() const;

	LIBUSDPROXY_API
	const std::string& GetString() const;

	LIBUSDPROXY_API
	bool IsEmpty() const;

	LIBUSDPROXY_API
	static
	bool IsValidIdentifier(const std::string& name);

private:
    pxr::SdfPath m_sdfPath;
};

} // namespace