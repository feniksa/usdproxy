#include "SdfValueTypeName.h"

namespace usdproxy
{

const pxr::SdfValueTypeName& SdfValueTypeName::Get() const
{
	return m_sdfValueTypeName;
}

}