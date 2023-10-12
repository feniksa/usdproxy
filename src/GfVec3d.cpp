#include "GfVec3d.h"

namespace usdproxy
{

GfVec3d::GfVec3d(double x, double y, double z)
: m_gfVec3d(x, y, z)
{
}
GfVec3d::GfVec3d(pxr::GfVec3d&& gfVec3D)
: m_gfVec3d(std::move(gfVec3D))
{
}

GfVec3d::GfVec3d(const pxr::GfVec3d& gfVec3D)
: m_gfVec3d(gfVec3D)
{
}

const pxr::GfVec3d& GfVec3d::Get() const
{
	return m_gfVec3d;
}

double GfVec3d::operator[](int index) const
{
	return m_gfVec3d[index];
}

double GfVec3d::Value(int index) const
{
	return this->operator[](index);
}

GfVec3d GfVec3d::ZAxis()
{
	return { pxr::GfVec3d::ZAxis() };
}

}