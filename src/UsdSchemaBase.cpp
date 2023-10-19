#include "UsdSchemaBase.h"

namespace usdproxy
{
UsdSchemaBase::UsdSchemaBase(const pxr::UsdSchemaBase& usdSchemaBase)
: m_usdSchemaBase(usdSchemaBase)
{
}

const pxr::UsdSchemaBase& UsdSchemaBase::Get() const
{
	return m_usdSchemaBase;
}
}

