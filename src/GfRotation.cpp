#include "GfRotation.h"
#include "GfQuatd.h"

namespace usdproxy
{

GfRotation::GfRotation(const pxr::GfRotation &gfRotation)
	: m_gfRotation(std::move(gfRotation))
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