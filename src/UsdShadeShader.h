#pragma once

#include "usdlib.h"
#include "UsdAttribute.h"
#include "UsdShadeInput.h"
#include "SdfValueTypeName.h"
#include <pxr/usd/usdShade/shader.h>

namespace usdproxy
{

class UsdStageWeakPtr;
class SdfPath;
class UsdShadeConnectableAPI;
class TfToken;
class UsdShadeOutput;

class UsdShadeShader
{
public:
	LIBUSDPROXY_API
	UsdShadeShader(pxr::UsdShadeShader&& usdShadeShader);

	LIBUSDPROXY_API
	static
	UsdShadeShader Define(const UsdStageWeakPtr& stage, const SdfPath& path);

	LIBUSDPROXY_API
	const pxr::UsdShadeShader& Get() const;

	LIBUSDPROXY_API
	UsdShadeConnectableAPI ConnectableAPI() const;

	LIBUSDPROXY_API
	UsdAttribute CreateIdAttr(const TfToken& token);

	LIBUSDPROXY_API
	UsdAttribute CreateImplementationSourceAttr(const TfToken& token);

	LIBUSDPROXY_API
	UsdShadeInput CreateInput(const TfToken& token, const SdfValueTypeName& sdfValue);

	LIBUSDPROXY_API
	UsdShadeInput CreateInput(const TfToken& token, const SdfValueTypeName::SdfValueTypeNames& sdfValue);

	LIBUSDPROXY_API
	UsdShadeOutput CreateOutput(const TfToken& token, const SdfValueTypeName& typeName);

	LIBUSDPROXY_API
	UsdShadeOutput CreateOutput(const TfToken& token, const SdfValueTypeName::SdfValueTypeNames& typeName);
private:
	pxr::UsdShadeShader m_usdShadeShader;
};

}