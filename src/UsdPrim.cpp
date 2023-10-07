#include "UsdPrim.h"

namespace usdproxy
{

const pxr::UsdPrim& UsdPrim::Get() const
{
	return m_usdPrim;
}

UsdPrim::UsdPrim(pxr::UsdPrim&& usdPrim) noexcept
: m_usdPrim(usdPrim)
{
}

}