#include "VtQuathArray.h"
#include "GfQuath.h"

namespace usdproxy
{

VtQuathArray::VtQuathArray(size_t size)
: m_vtQuathArray(size)
{
}

void VtQuathArray::push_back(const usdproxy::GfQuath& quath)
{
	m_vtQuathArray.push_back(quath.Get());
}

const pxr::VtQuathArray& VtQuathArray::Get() const
{
	return m_vtQuathArray;
}
}

