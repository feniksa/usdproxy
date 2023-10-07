#include "UsdGeomTokens.h"

namespace usdproxy
{

UsdGeomTokens::UsdGeomTokens(Token token)
: m_token(token)
{
}

pxr::TfToken UsdGeomTokens::toPxrToken()
{
	switch (m_token) {
	case faceVarying:
		return pxr::UsdGeomTokens->faceVarying;
	}
	return pxr::UsdGeomTokens->faceVarying;
}

}
