#include "UsdGeomTokens.h"

namespace usdproxy
{

UsdGeomTokens::UsdGeomTokens(Token token)
: m_token(token)
{
}

const pxr::TfToken UsdGeomTokens::Get() const
{
	return toPxrToken();
}

const pxr::TfToken UsdGeomTokens::toPxrToken() const
{
	switch (m_token) {
	case faceVarying:
		return pxr::UsdGeomTokens->faceVarying;
	case varying:
		return pxr::UsdGeomTokens->varying;
	}
	return pxr::UsdGeomTokens->faceVarying;
}

}
