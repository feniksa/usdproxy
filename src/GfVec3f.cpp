#include "GfVec3f.h"
#include "GfVec3d.h"

namespace usdproxy
{

GfVec3f::GfVec3f(const pxr::GfVec3f& gfVec3f)
: m_gfVec3f(gfVec3f)
{
}

GfVec3f::GfVec3f(float x, float y, float z)
: m_gfVec3f(x, y, z)
{
}

GfVec3f::GfVec3f(const GfVec3f& gfVec3F)
: m_gfVec3f(gfVec3F.Get())
{
}

GfVec3f::GfVec3f(const GfVec3d& gfVec3d)
: m_gfVec3f(gfVec3d.Get())
{
}

const pxr::GfVec3f& GfVec3f::Get() const
{
	return m_gfVec3f;
}

}