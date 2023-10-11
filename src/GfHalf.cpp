#include "GfHalf.h"

namespace usdproxy
{

GfHalf::GfHalf(float h)
: m_gfHalf(h)
{
}

const pxr::GfHalf& GfHalf::Get() const
{
	return m_gfHalf;
}

}

