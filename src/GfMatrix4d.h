#pragma once

#include <pxr/base/gf/matrix4d.h>
#include "usdlib.h"

namespace usdproxy
{

class GfRotation;
class GfVec3d;

class GfMatrix4d
{
public:
	LIBUSDPROXY_API
	GfMatrix4d() = default;

	LIBUSDPROXY_API
	GfMatrix4d(const pxr::GfMatrix4d& m);

	LIBUSDPROXY_API
	GfMatrix4d(double m00, double m01, double m02, double m03,
			   double m10, double m11, double m12, double m13,
			   double m20, double m21, double m22, double m23,
			   double m30, double m31, double m32, double m33);

	LIBUSDPROXY_API
	void CopyFromArray(const double array[4][4]);

	LIBUSDPROXY_API
	GfMatrix4d& Set(double m00, double m01, double m02, double m03,
					double m10, double m11, double m12, double m13,
					double m20, double m21, double m22, double m23,
					double m30, double m31, double m32, double m33);

	LIBUSDPROXY_API
	GfMatrix4d GetTranspose() const;

	LIBUSDPROXY_API
	GfVec3d ExtractTranslation() const;

	LIBUSDPROXY_API
	GfRotation ExtractRotation() const;

	LIBUSDPROXY_API
	const pxr::GfMatrix4d& Get() const;
private:
	pxr::GfMatrix4d m_gfMatrix4d;
};
}