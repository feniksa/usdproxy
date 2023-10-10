#include "UsdShadeOutput.h"
#include "UsdShadeConnectableAPI.h"
#include "TfToken.h"

namespace usdproxy
{

UsdShadeOutput::UsdShadeOutput(pxr::UsdShadeOutput &&usdShadeOutput)
: m_usdShadeOutput(std::move(usdShadeOutput))
{
}

bool UsdShadeOutput::ConnectToSource(const UsdShadeConnectableAPI& api, const TfToken& token)
{
	return m_usdShadeOutput.ConnectToSource(api.Get(), token.Get());
}


}


