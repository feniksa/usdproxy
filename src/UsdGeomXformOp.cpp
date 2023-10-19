#include "UsdGeomXformOp.h"
#include "GfMatrix4d.h"

namespace usdproxy
{

UsdGeomXformOp::UsdGeomXformOp(const pxr::UsdGeomXformOp& usdGeomXformOp)
: m_usdGeomXformOp(usdGeomXformOp)
{
}

bool UsdGeomXformOp::Set(const GfMatrix4d& matrix)
{
	return m_usdGeomXformOp.Set(matrix.Get());
}

const pxr::UsdGeomXformOp& UsdGeomXformOp::Get() const
{
	return m_usdGeomXformOp;
}

}