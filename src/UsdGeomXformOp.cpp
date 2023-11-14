#include "UsdGeomXformOp.h"
#include "GfMatrix4d.h"
#include "GfQuatd.h"
#include "GfQuath.h"
#include "GfVec3d.h"
#include "GfVec3f.h"

namespace usdproxy
{

UsdGeomXformOp::UsdGeomXformOp(const pxr::UsdGeomXformOp &usdGeomXformOp)
	: m_usdGeomXformOp(usdGeomXformOp)
{
}

bool UsdGeomXformOp::Set(const GfMatrix4d &matrix)
{
	return m_usdGeomXformOp.Set(matrix.Get());
}
bool UsdGeomXformOp::Set(const GfQuath &quath)
{
	return m_usdGeomXformOp.Set(quath.Get());
}

bool UsdGeomXformOp::Set(const GfQuatd &quatd)
{
	return m_usdGeomXformOp.Set(quatd.Get());
}

const pxr::UsdGeomXformOp &UsdGeomXformOp::Get() const
{
	return m_usdGeomXformOp;
}

bool UsdGeomXformOp::Set(const GfVec3f& gfVec3f)
{
	return m_usdGeomXformOp.Set(gfVec3f.Get());
}

bool UsdGeomXformOp::Set(const GfVec3d& gfVec3d)
{
	return m_usdGeomXformOp.Set(gfVec3d.Get());
}

}