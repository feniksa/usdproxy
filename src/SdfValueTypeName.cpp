#include "SdfValueTypeName.h"


namespace usdproxy
{

pxr::SdfValueTypeName convert(SdfValueTypeName::SdfValueTypeNames typeName)
{
	switch (typeName) {
	case SdfValueTypeName::Asset:
		return pxr::SdfValueTypeNames->Asset;
	case SdfValueTypeName::Float:
		return pxr::SdfValueTypeNames->Float;
	case SdfValueTypeName::Int:
		return pxr::SdfValueTypeNames->Int;
	case SdfValueTypeName::Color3f:
		return pxr::SdfValueTypeNames->Color3f;
	case SdfValueTypeName::String:
		return pxr::SdfValueTypeNames->String;
	case SdfValueTypeName::Token:
		return pxr::SdfValueTypeNames->Token;
	case SdfValueTypeName::Float2:
		return pxr::SdfValueTypeNames->Float2;
	case SdfValueTypeName::Vector3f:
		return pxr::SdfValueTypeNames->Vector3f;
	case SdfValueTypeName::TexCoord2fArray:
		return pxr::SdfValueTypeNames->TexCoord2fArray;
	default:
		return pxr::SdfValueTypeNames->String;
	}
}

SdfValueTypeName::SdfValueTypeName(const pxr::SdfValueTypeName& typeName)
: m_sdfValueTypeName(typeName)
{

}

SdfValueTypeName::SdfValueTypeName(SdfValueTypeNames typeName)
: m_sdfValueTypeName(convert(typeName))
{
}

const pxr::SdfValueTypeName& SdfValueTypeName::Get() const
{
	return m_sdfValueTypeName;
}

}