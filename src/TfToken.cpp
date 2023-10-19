#include "TfToken.h"

namespace usdproxy
{

TfToken::TfToken(const std::string &value)
: m_tfToken(value)
{
}

TfToken::TfToken(const TfToken& token)
: m_tfToken(token.m_tfToken)
{
}

const pxr::TfToken &TfToken::Get() const
{
	return m_tfToken;
}

}
