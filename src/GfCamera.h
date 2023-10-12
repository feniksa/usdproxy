#pragma once

#include "usdlib.h"

#include <pxr/base/gf/camera.h>

namespace usdproxy
{
class GfCamera
{
public:
	enum FOVDirection
	{
		FOVHorizontal,
		FOVVertical
	}; // check for convert function!

	LIBUSDPROXY_API
	GfCamera() = default;

	LIBUSDPROXY_API
	GfCamera(pxr::GfCamera&& gfCamera);

	LIBUSDPROXY_API
	void SetOrthographicFromAspectRatioAndSize(float aspectRatio, float orthographicSize, FOVDirection direction);

	LIBUSDPROXY_API
	void SetPerspectiveFromAspectRatioAndFieldOfView(float aspectRatio, float fieldOfView, FOVDirection direction);

	LIBUSDPROXY_API
	const pxr::GfCamera& Get() const;
private:
	pxr::GfCamera m_gfCamera;
};

}