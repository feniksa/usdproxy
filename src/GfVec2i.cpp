#include "GfVec2i.h"

namespace usdproxy
{
GfVec2i::GfVec2i(int x, int y)
: m_gfVec2f(x, y)
{
}

const pxr::GfVec2i& GfVec2i::Get() const
{
	return m_gfVec2f;
}

}