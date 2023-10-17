#include "UsdShadeConnectableAPI.h"

namespace usdproxy
{
UsdShadeConnectableAPI::UsdShadeConnectableAPI(const pxr::UsdShadeConnectableAPI& usdShadeConnectableAPI)
: m_usdShadeConnectableAPI(std::move(usdShadeConnectableAPI))
{
}

const pxr::UsdShadeConnectableAPI& UsdShadeConnectableAPI::Get() const
{
	return m_usdShadeConnectableAPI;
}

}