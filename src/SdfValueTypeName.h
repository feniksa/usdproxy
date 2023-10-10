#pragma once

#include <pxr/usd/sdf/valueTypeName.h>
#include "usdlib.h"

namespace usdproxy
{
class SdfValueTypeName
{
public:
	SdfValueTypeName() = default;

	const pxr::SdfValueTypeName& Get() const;

private:
	pxr::SdfValueTypeName m_sdfValueTypeName;

};
}