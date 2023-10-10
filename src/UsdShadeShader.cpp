#include "UsdShadeShader.h"
#include "UsdStageWeakPtr.h"
#include "SdfPath.h"
#include "UsdShadeConnectableAPI.h"
#include "TfToken.h"
#include "SdfValueTypeName.h"

namespace usdproxy
{

UsdShadeShader::UsdShadeShader(pxr::UsdShadeShader&& usdShadeShader)
: m_usdShadeShader(std::move(usdShadeShader))
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

}