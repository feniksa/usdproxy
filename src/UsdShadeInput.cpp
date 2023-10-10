#include "UsdShadeInput.h"

namespace usdproxy
{

UsdShadeInput::UsdShadeInput(pxr::UsdShadeInput&& usdShadeInput)
: m_usdShadeInput(std::move(usdShadeInput))
{
}

const pxr::UsdShadeInput& UsdShadeInput::Get() const
{
	return m_usdShadeInput;
}

}