#include "VtIntArray.h"

namespace usdproxy
{

void VtIntArray::push_back(int data)
{
	m_vtIntArray.push_back(data);
}

const pxr::VtIntArray& VtIntArray::Get() const
{
	return m_vtIntArray;
}

}