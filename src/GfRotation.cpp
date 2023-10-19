#include "GfRotation.h"
#include "GfQuatd.h"
#include "GfVec3d.h"

namespace usdproxy
{

GfRotation::GfRotation(const pxr::GfRotation& gfRotation)
: m_gfRotation(gfRotation)
{
}

GfRotation::GfRotation(const GfVec3d& rotateFrom, const GfVec3d& rotateTo)
: m_gfRotation(rotateFrom.Get(), rotateTo.Get())
{
}

GfRotation::GfRotation(const GfVec3d& axis, double angle)
: m_gfRotation(axis.Get(), angle)
{
}

const pxr::GfRotation &GfRotation::Get() const
{
	return m_gfRotation;
}

GfQuatd GfRotation::GetQuat() const
{
	return { m_gfRotation.GetQuat() };
}

}