#include "GfQuatd.h"
#include "GfVec3d.h"

namespace usdproxy
{

GfQuatd::GfQuatd(const pxr::GfQuatd& gfQuatd)
: m_gfQuatd(gfQuatd)
{

}

double GfQuatd::GetReal() const
{
	return m_gfQuatd.GetReal();
}

GfVec3d GfQuatd::GetImaginary() const
{
	return GfVec3d(m_gfQuatd.GetImaginary());
}

const pxr::GfQuatd& GfQuatd::Get() const
{
	return m_gfQuatd;
}

}