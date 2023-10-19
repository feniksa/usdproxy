#include "UsdModelAPI.h"
#include "TfToken.h"
#include "UsdSchemaBase.h"
#include "UsdGeomXform.h"

namespace usdproxy
{

UsdModelAPI::UsdModelAPI(const UsdPrim& usdPrim)
: m_usdModelAPI(usdPrim.Get())
{
}

UsdModelAPI::UsdModelAPI(const pxr::UsdSchemaBase& usdSchemaBase)
: m_usdModelAPI(usdSchemaBase)
{
}

UsdModelAPI::UsdModelAPI(const UsdGeomXform& usdGeomXform)
: m_usdModelAPI(usdGeomXform.Get())
{
}

UsdModelAPI::UsdModelAPI(const UsdSchemaBase& usdSchemaBase)
: m_usdModelAPI(usdSchemaBase.Get())
{
}

bool UsdModelAPI::SetKind(const KindToken::KindTokens& token)
{
	return SetKind(KindToken(token).Get());
}

bool UsdModelAPI::SetKind(const TfToken& token)
{
	return m_usdModelAPI.SetKind(token.Get());
}

const pxr::UsdModelAPI& UsdModelAPI::Get() const
{
	return m_usdModelAPI;
}

}

