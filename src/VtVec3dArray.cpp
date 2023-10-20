#include "VtVec3dArray.h"
#include "GfVec3d.h"

namespace usdproxy
{

void VtVec3dArray::push_back(const GfVec3d &xyz)
{
	m_vtVec3dArray.push_back(xyz.Get());
}

const pxr::VtVec3dArray& VtVec3dArray::Get() const
{
	return m_vtVec3dArray;
}

}
