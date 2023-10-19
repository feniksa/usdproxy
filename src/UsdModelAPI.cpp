#include "UsdModelAPI.h"
#include "TfToken.h"

namespace usdproxy
{

UsdModelAPI::UsdModelAPI(const UsdPrim& usdPrim)
: m_usdModelAPI(usdPrim.Get())
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

