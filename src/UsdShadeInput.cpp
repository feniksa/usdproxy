#include "UsdShadeInput.h"
#include "SdfAssetPath.h"
#include "GfVec3f.h"
#include "TfToken.h"
#include "UsdShadeOutput.h"

namespace usdproxy
{

UsdShadeInput::UsdShadeInput(const pxr::UsdShadeInput& usdShadeInput)
: m_usdShadeInput(usdShadeInput)
{
}

const pxr::UsdShadeInput& UsdShadeInput::Get() const
{
	return m_usdShadeInput;
}

bool UsdShadeInput::Set(const SdfAssetPath& path)
{
	return m_usdShadeInput.Set(path.Get());
}

bool UsdShadeInput::Set(float value)
{
	return m_usdShadeInput.Set(value);
}

bool UsdShadeInput::Set(int value)
{
	return m_usdShadeInput.Set(value);
}

bool UsdShadeInput::Set(unsigned int value)
{
	return m_usdShadeInput.Set(value);
}

bool UsdShadeInput::Set(const GfVec3f& value)
{
	return m_usdShadeInput.Set(value.Get());
}

bool UsdShadeInput::Set(const TfToken& token)
{
	return m_usdShadeInput.Set(token.Get());
}

bool UsdShadeInput::Set(const std::string& str)
{
	return m_usdShadeInput.Set(str);
}

void UsdShadeInput::ConnectToSource(const UsdShadeOutput& output)
{
	m_usdShadeInput.ConnectToSource(output.Get());
}

}