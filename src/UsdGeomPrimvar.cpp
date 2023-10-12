#include "UsdGeomPrimvar.h"

namespace usdproxy
{

UsdGeomPrimvar::UsdGeomPrimvar(pxr::UsdGeomPrimvar&& usdGeomPrimvar)
: m_usdGeomPrimvar(std::move(usdGeomPrimvar))
{
}

}