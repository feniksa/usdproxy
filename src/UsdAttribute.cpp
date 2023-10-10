#include "UsdAttribute.h"

namespace usdproxy
{

UsdAttribute::UsdAttribute(pxr::UsdAttribute&& usdAttribute)
: m_usdAttribute(std::move(usdAttribute))
{
}

}