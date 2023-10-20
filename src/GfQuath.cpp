#include "GfQuath.h"
#include "GfHalf.h"
#include "GfQuatd.h"

namespace usdproxy
{
GfQuath::GfQuath(GfHalf realVal)
: m_gfQuath(realVal.Get())
{
}

GfQuath::GfQuath(const GfQuatd& gfQuatd)
: m_gfQuath(gfQuatd.Get())
{
}

GfQuath::GfQuath(GfHalf real, GfHalf i, GfHalf j, GfHalf k)
: m_gfQuath(real.Get(), i.Get(), j.Get(), k.Get())
{
}

GfQuath::GfQuath(float real, float i, float j, float k)
: GfQuath(GfHalf(real), GfHalf(i), GfHalf(j), GfHalf(k))
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