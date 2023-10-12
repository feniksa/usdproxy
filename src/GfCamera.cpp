#include "GfCamera.h"

namespace
{

pxr::GfCamera::FOVDirection convertToPxr(usdproxy::GfCamera::FOVDirection direction)
{
	switch (direction) {
	case usdproxy::GfCamera::FOVHorizontal:
		return pxr::GfCamera::FOVDirection::FOVHorizontal;
	case usdproxy::GfCamera::FOVVertical:
		return pxr::GfCamera::FOVDirection::FOVVertical;
	default:
		return pxr::GfCamera::FOVDirection::FOVHorizontal;
	}
}

}

namespace usdproxy
{
GfCamera::GfCamera(pxr::GfCamera&& gfCamera)
: m_gfCamera(gfCamera)
{
}

void GfCamera::SetOrthographicFromAspectRatioAndSize(float aspectRatio, float orthographicSize, FOVDirection direction)
{
	m_gfCamera.SetOrthographicFromAspectRatioAndSize(aspectRatio, orthographicSize, convertToPxr(direction));
}

void GfCamera::SetPerspectiveFromAspectRatioAndFieldOfView(float aspectRatio, float fieldOfView, FOVDirection direction)
{
	m_gfCamera.SetPerspectiveFromAspectRatioAndFieldOfView(aspectRatio, fieldOfView, convertToPxr(direction));
}

const pxr::GfCamera& GfCamera::Get() const
{
	return m_gfCamera;
}

}

