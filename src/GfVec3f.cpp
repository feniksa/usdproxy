#include "GfVec3f.h"

namespace usdproxy
{
GfVec3f::GfVec3f(float x, float y, float z)
: m_gfVec3f(x, y, z)
{
}

const pxr::GfVec3f& GfVec3f::Get() const
{
	return m_gfVec3f;
}

}