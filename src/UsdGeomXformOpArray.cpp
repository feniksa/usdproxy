#include "UsdGeomXformOpArray.h"
#include "UsdGeomXformOp.h"

namespace usdproxy
{

const std::vector<pxr::UsdGeomXformOp>& UsdGeomXformOpArray::Get() const
{
	return m_usdGeomXformOpArray;
}

void UsdGeomXformOpArray::push_back(const pxr::UsdGeomXformOp& operation)
{
	return m_usdGeomXformOpArray.push_back(operation);
}

void UsdGeomXformOpArray::push_back(const UsdGeomXformOp& operation)
{
	m_usdGeomXformOpArray.push_back(operation.Get());
}

}