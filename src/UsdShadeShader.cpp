#include "UsdShadeShader.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "UsdShadeConnectableAPI.h"
#include "TfToken.h"
#include "SdfValueTypeName.h"
#include "UsdShadeOutput.h"

namespace usdproxy
{

UsdShadeShader::UsdShadeShader(const pxr::UsdShadeShader& usdShadeShader)
: m_usdShadeShader(usdShadeShader)
{
}

UsdShadeShader UsdShadeShader::Define(const UsdStageWeakPtr& stage, const SdfPath& path)
{
	return UsdShadeShader(pxr::UsdShadeShader::Define(stage.Get(), path.Get()));
}

UsdShadeConnectableAPI UsdShadeShader::ConnectableAPI() const
{
	return UsdShadeConnectableAPI(m_usdShadeShader.ConnectableAPI());
}

const pxr::UsdShadeShader& UsdShadeShader::Get() const
{
	return m_usdShadeShader;
}

UsdAttribute UsdShadeShader::CreateIdAttr(const TfToken& token)
{
	const pxr::VtValue value(token.Get());
	return UsdAttribute(m_usdShadeShader.CreateIdAttr(value));
}

UsdAttribute UsdShadeShader::CreateImplementationSourceAttr(const TfToken& token)
{
	const pxr::VtValue value(token.Get());
	return UsdAttribute(m_usdShadeShader.CreateImplementationSourceAttr(value));
}

UsdShadeInput UsdShadeShader::CreateInput(const TfToken& token, const SdfValueTypeName& sdfValueTypeName)
{
	return { m_usdShadeShader.CreateInput(token.Get(), sdfValueTypeName.Get()) };
}

UsdShadeInput UsdShadeShader::CreateInput(const TfToken& token, const SdfValueTypeName::SdfValueTypeNames& sdfValue)
{
	return CreateInput(token, SdfValueTypeName(sdfValue));
}

UsdShadeOutput UsdShadeShader::CreateOutput(const TfToken& token, const SdfValueTypeName& typeName)
{
	return { m_usdShadeShader.CreateOutput(token.Get(), typeName.Get()) };
}

UsdShadeOutput UsdShadeShader::CreateOutput(const TfToken& token, const SdfValueTypeName::SdfValueTypeNames& typeName)
{
	return CreateOutput(token, SdfValueTypeName(typeName));
}

}