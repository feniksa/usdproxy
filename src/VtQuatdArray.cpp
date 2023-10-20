#include "VtQuatdArray.h"
#include "GfQuatd.h"

namespace usdproxy
{

VtQuatdArray::VtQuatdArray(size_t size)
	: m_vtQuathArray(size)
{
}

void VtQuatdArray::push_back(const usdproxy::GfQuatd& quath)
{
	m_vtQuathArray.push_back(quath.Get());
}

const pxr::VtQuatdArray& VtQuatdArray::Get() const
{
	return m_vtQuathArray;
}
}

