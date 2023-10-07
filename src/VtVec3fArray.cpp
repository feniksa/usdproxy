#include "VtVec3fArray.h"

namespace usdproxy
{

void VtVec3fArray::push_back(const GfVec3f &xyz)
{
	m_vtVec3fArray.push_back(xyz.Get());
}


const pxr::VtVec3fArray& VtVec3fArray::Get() const
{
	return m_vtVec3fArray;
}

}
