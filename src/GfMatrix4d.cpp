#include "GfMatrix4d.h"
#include "GfVec3d.h"
#include "GfRotation.h"

namespace usdproxy
{

GfMatrix4d::GfMatrix4d(double* transformation)
: m_gfMatrix4d(
	transformation[0 * 4 + 0], transformation[0 * 4 + 1], transformation[0 * 4 + 2], transformation[0 * 4 + 3],
	transformation[1 * 4 + 0], transformation[1 * 4 + 1], transformation[1 * 4 + 2], transformation[1 * 4 + 3],
	transformation[2 * 4 + 0], transformation[2 * 4 + 1], transformation[2 * 4 + 2], transformation[2 * 4 + 3],
	transformation[3 * 4 + 0], transformation[3 * 4 + 1], transformation[3 * 4 + 2], transformation[3 * 4 + 3])
{
}


GfMatrix4d::GfMatrix4d(double m00, double m01, double m02, double m03,
		   double m10, double m11, double m12, double m13,
		   double m20, double m21, double m22, double m23,
		   double m30, double m31, double m32, double m33) {
	Set(m00, m01, m02, m03,
		m10, m11, m12, m13,
		m20, m21, m22, m23,
		m30, m31, m32, m33);
}
GfMatrix4d& GfMatrix4d::Set(double m00, double m01, double m02, double m03,
				double m10, double m11, double m12, double m13,
				double m20, double m21, double m22, double m23,
				double m30, double m31, double m32, double m33) {
	m_gfMatrix4d[0][0] = m00; m_gfMatrix4d[0][1] = m01; m_gfMatrix4d[0][2] = m02; m_gfMatrix4d[0][3] = m03;
	m_gfMatrix4d[1][0] = m10; m_gfMatrix4d[1][1] = m11; m_gfMatrix4d[1][2] = m12; m_gfMatrix4d[1][3] = m13;
	m_gfMatrix4d[2][0] = m20; m_gfMatrix4d[2][1] = m21; m_gfMatrix4d[2][2] = m22; m_gfMatrix4d[2][3] = m23;
	m_gfMatrix4d[3][0] = m30; m_gfMatrix4d[3][1] = m31; m_gfMatrix4d[3][2] = m32; m_gfMatrix4d[3][3] = m33;
	return *this;
}

GfMatrix4d::GfMatrix4d(const pxr::GfMatrix4d& m)
: m_gfMatrix4d(m)
{
}

void GfMatrix4d::CopyFromArray(const double array[4][4])
{
	m_gfMatrix4d.Set(array);
}
LIBUSDPROXY_API
GfMatrix4d GfMatrix4d::GetTranspose() const
{
	return GfMatrix4d(m_gfMatrix4d.GetTranspose());
}

const pxr::GfMatrix4d& GfMatrix4d::Get() const
{
	return m_gfMatrix4d;
}

GfVec3d GfMatrix4d::ExtractTranslation() const
{
	return { m_gfMatrix4d.ExtractTranslation() };
}

GfRotation GfMatrix4d::ExtractRotation() const
{
	return { m_gfMatrix4d.ExtractRotation() };
}

GfMatrix4d& GfMatrix4d::SetIdentity()
{
	m_gfMatrix4d.SetIdentity();

	return *this;
}

GfMatrix4d& GfMatrix4d::SetRotate(const GfRotation& rotation)
{
	m_gfMatrix4d.SetRotate(rotation.Get());
	return *this;
}

GfMatrix4d& GfMatrix4d::SetScale(double scaleFactor)
{
	m_gfMatrix4d.SetScale(scaleFactor);
	return *this;
}

}