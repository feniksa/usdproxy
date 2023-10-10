#pragma once

#include "usdlib.h"
#include <pxr/usd/usdShade/input.h>

namespace usdproxy
{

class SdfAssetPath;
class GfVec3f;
class TfToken;
class UsdShadeOutput;

class UsdShadeInput
{
public:
	LIBUSDPROXY_API
	UsdShadeInput() = default;

	LIBUSDPROXY_API
	UsdShadeInput(pxr::UsdShadeInput&& usdShadeInput);

	LIBUSDPROXY_API
	void ConnectToSource(const UsdShadeOutput&);

	LIBUSDPROXY_API
	bool Set(const SdfAssetPath& path);

	LIBUSDPROXY_API
	bool Set(float value);

	LIBUSDPROXY_API
	bool Set(int value);

	LIBUSDPROXY_API
	bool Set(unsigned int value);

	LIBUSDPROXY_API
	bool Set(const GfVec3f& value);

	LIBUSDPROXY_API
	bool Set(const TfToken& token);

	LIBUSDPROXY_API
	bool Set(const std::string& str);

	LIBUSDPROXY_API
	const pxr::UsdShadeInput& Get() const;
private:
	pxr::UsdShadeInput m_usdShadeInput;
};

}