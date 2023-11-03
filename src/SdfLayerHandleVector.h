#pragma once

#include "usdlib.h"

#include <pxr/usd/sdf/layer.h>

namespace usdproxy
{

class SdfLayerHandleVector
{
public:
	LIBUSDPROXY_API
	SdfLayerHandleVector() = default;

	LIBUSDPROXY_API
	SdfLayerHandleVector(const SdfLayerHandleVector& sdfLayerHandleVector) = default;

	LIBUSDPROXY_API
	SdfLayerHandleVector(const pxr::SdfLayerHandleVector& sdfLayerHandleVector);

	LIBUSDPROXY_API
	int Size() const;

	LIBUSDPROXY_API
	const pxr::SdfLayerHandle& Get(int index);

	LIBUSDPROXY_API
	const pxr::SdfLayerHandleVector& Get() const;
private:
	pxr::SdfLayerHandleVector m_sdfLayerHandleVector;
};

}