#include "UsdShadeOutput.h"
#include "UsdShadeConnectableAPI.h"
#include "TfToken.h"

namespace usdproxy
{

UsdShadeOutput::UsdShadeOutput(const pxr::UsdShadeOutput& usdShadeOutput)
: m_usdShadeOutput(usdShadeOutput)
{
}

bool UsdShadeOutput::ConnectToSource(const UsdShadeConnectableAPI& api, const TfToken& token)
{
	return m_usdShadeOutput.ConnectToSource(api.Get(), token.Get());
}

const pxr::UsdShadeOutput& UsdShadeOutput::Get() const
{
	return m_usdShadeOutput;
}

}


