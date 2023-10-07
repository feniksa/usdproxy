#include "TfToken.h"

namespace usdproxy
{

TfToken::TfToken(const std::string &value)
: m_tfToken(value)
{
}

const pxr::TfToken &TfToken::Get() const
{
	return m_tfToken;
}

}
