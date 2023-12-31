#include "UsdAttribute.h"
#include "VtVec2fArray.h"

namespace usdproxy
{

UsdAttribute::UsdAttribute(const pxr::UsdAttribute& usdAttribute)
: m_usdAttribute(usdAttribute)
{
}

bool UsdAttribute::Set(const VtVec2fArray& array)
{
	return m_usdAttribute.Set(array.Get());
}

}