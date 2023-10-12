#pragma once

#include "usdlib.h"
#include <pxr/usd/sdf/valueTypeName.h>
#include "pxr/usd/sdf/types.h"

namespace usdproxy
{

class SdfValueTypeName
{
public:
	enum SdfValueTypeNames
	{
		Asset,
		Float,
		Int,
		Color3f,
		String,
		Token,
		Float2,
		Vector3f,
		TexCoord2fArray
	}; // don't forget to check SdfValueTypeName::convert!

	LIBUSDPROXY_API
	SdfValueTypeName() = default;

	LIBUSDPROXY_API
	SdfValueTypeName(pxr::SdfValueTypeName&& typeName);

	LIBUSDPROXY_API
	SdfValueTypeName(SdfValueTypeNames typeName);

	LIBUSDPROXY_API
	const pxr::SdfValueTypeName& Get() const;
private:
	pxr::SdfValueTypeName m_sdfValueTypeName;

};
}