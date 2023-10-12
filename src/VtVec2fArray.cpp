#include "VtVec2fArray.h"

namespace usdproxy
{

void VtVec2fArray::push_back(const GfVec2f& point)
{
	m_vtVec2fArray.push_back(point.Get());
}

const pxr::VtVec2fArray& VtVec2fArray::Get() const
{
	return m_vtVec2fArray;
}

}