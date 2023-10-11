#include "GfVec2f.h"

namespace usdproxy
{
GfVec2f::GfVec2f(float x, float y)
: m_gfVec2f(x, y)
{
}

const pxr::GfVec2f& GfVec2f::Get() const
{
	return m_gfVec2f;
}

}