#include "GfQuath.h"

namespace usdproxy
{

GfQuath::GfQuath::GfQuath(pxr::GfQuath&& gfQuath)
: m_gfQuath(std::move(gfQuath))
{
}

GfQuath::GfQuath(const pxr::GfQuath& gfQuath)
: m_gfQuath(gfQuath)
{
}

const pxr::GfQuath& GfQuath::Get() const
{
	return m_gfQuath;
}

}