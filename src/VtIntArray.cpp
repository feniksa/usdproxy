#include "VtIntArray.h"

namespace usdproxy
{

VtIntArray::VtIntArray(const VtIntArray& other)
: m_vtIntArray(other.m_vtIntArray)
{
}

VtIntArray::VtIntArray(VtIntArray&& other) noexcept
{
	std::swap(m_vtIntArray, other.m_vtIntArray);
}

void VtIntArray::push_back(int data)
{
	m_vtIntArray.push_back(data);
}

const pxr::VtIntArray& VtIntArray::Get() const
{
	return m_vtIntArray;
}

}