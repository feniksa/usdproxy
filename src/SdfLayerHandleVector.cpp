#include "SdfLayerHandleVector.h"

namespace usdproxy
{
SdfLayerHandleVector::SdfLayerHandleVector(const pxr::SdfLayerHandleVector& sdfLayerHandleVector)
: m_sdfLayerHandleVector(sdfLayerHandleVector)
{

}
const pxr::SdfLayerHandleVector& SdfLayerHandleVector::Get() const
{
	return m_sdfLayerHandleVector;
}

LIBUSDPROXY_API
int SdfLayerHandleVector::Size() const
{
	return m_sdfLayerHandleVector.size();
}

LIBUSDPROXY_API
const pxr::SdfLayerHandle& SdfLayerHandleVector::Get(int index)
{
	return m_sdfLayerHandleVector[index];
}

}