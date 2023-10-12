#include "UsdTimeCode.h"

namespace usdproxy
{
UsdTimeCode::UsdTimeCode(double time)
: m_usdTimeCode(time)
{
}

UsdTimeCode::UsdTimeCode(pxr::UsdTimeCode &&usdTimeCode)
: m_usdTimeCode(usdTimeCode)
{
}

const pxr::UsdTimeCode& UsdTimeCode::Get() const
{
	return m_usdTimeCode;
}

}


