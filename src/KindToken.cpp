#include "KindToken.h"

namespace usdproxy
{

TfToken KindToken::Get() const
{
	switch (m_token) {
	case component:
		return TfToken(pxr::KindTokens->component);
	default:
		return TfToken(pxr::KindTokens->component);
	}
}

}