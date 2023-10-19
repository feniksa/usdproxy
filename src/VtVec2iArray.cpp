#include "VtVec2iArray.h"

namespace usdproxy
{

void VtVec2iArray::push_back(const GfVec2i& point)
{
	m_vtVec2iArray.push_back(point.Get());
}

const pxr::VtVec2iArray& VtVec2iArray::Get() const
{
	return m_vtVec2iArray;
}

}

