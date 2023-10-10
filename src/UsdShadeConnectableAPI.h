#include "usdlib.h"

#include <pxr/usd/usdShade/connectableAPI.h>

namespace usdproxy
{

class UsdShadeConnectableAPI
{
public:
	LIBUSDPROXY_API
	UsdShadeConnectableAPI(pxr::UsdShadeConnectableAPI&& usdShadeConnectableAPI);

	LIBUSDPROXY_API
	const pxr::UsdShadeConnectableAPI& Get() const;
private:
	pxr::UsdShadeConnectableAPI m_usdShadeConnectableAPI;
};

}

