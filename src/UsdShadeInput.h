#pragma once

#include "usdlib.h"
#include <pxr/usd/usdShade/input.h>

namespace usdproxy
{

class UsdShadeInput
{
public:
	UsdShadeInput() = default;
	UsdShadeInput(pxr::UsdShadeInput&& usdShadeInput);

	const pxr::UsdShadeInput& Get() const;
private:
	pxr::UsdShadeInput m_usdShadeInput;
};

}