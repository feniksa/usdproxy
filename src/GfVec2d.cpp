#include "GfVec2d.h"

namespace usdproxy
{

const pxr::GfVec2d& GfVec2d::Get() const
{
	return m_gfVec2d;
}

GfVec2d::GfVec2d(double x, double y)
: m_gfVec2d(x, y)
{
}

}
