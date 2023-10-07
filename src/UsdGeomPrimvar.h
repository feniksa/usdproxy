#pragma once

#include "usdlib.h"
#include <pxr/usd/usdGeom/primvar.h>

namespace usdproxy
{

class UsdGeomPrimvar
{
public:
	LIBUSDPROXY_API
	UsdGeomPrimvar() = default;

private:
	pxr::UsdGeomPrimvar m_usdGeomPrimvar;
};

}