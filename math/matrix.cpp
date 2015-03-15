#include "commonMath.h"
#include "matrix.h"

namespace SpaceWitch
{
	Matrix::Matrix()
	{
		m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0;
		m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0;
		m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0;
	}

	Matrix::Matrix(double m00, double m01, double m02, double m10,
		double m11, double m12, double m20, double m21, double m22)
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
	}

	Matrix::Matrix(Vector m1, Vector m2, Vector m3)
	{
		m[0][0] = m1.x; m[0][1] = m1.y; m[0][2] = m1.z;
		m[1][0] = m2.x; m[1][1] = m2.y; m[1][2] = m2.z;
		m[2][0] = m3.x; m[2][1] = m3.y; m[2][2] = m3.z;
	}

	void Matrix::Rot(double X, double Y, double Z)
	{
		double	cx = cos(X), sx = sin(X),
			cy = cos(Y), sy = sin(Y),
			cz = cos(Z), sz = sin(Z);

		m[0][0] = cy*cz;
		m[1][0] = -cy*sz;
		m[2][0] = sy;

		m[0][1] = sx*sy*cz + cx*sz;
		m[1][1] = -sx*sy*sz + cx*cz;
		m[2][1] = -sx*cy;

		m[0][2] = -cx*sy*cz + sx*sz;
		m[1][2] = cx*sy*sz + sx*cz;
		m[2][2] = cx*cy;
	}

	void Matrix::Rot(Vector &v)
	{
		Rot(v.x, v.y, v.z);
	}

	Matrix &Matrix::add(Matrix &m1, Matrix &m2, Matrix &result)
	{
		result.m[0][0] = m1.m[0][0] + m2.m[0][0];
		result.m[0][1] = m1.m[0][1] + m2.m[0][1];
		result.m[0][2] = m1.m[0][2] + m2.m[0][2];
		result.m[1][0] = m1.m[1][0] + m2.m[1][0];
		result.m[1][1] = m1.m[1][1] + m2.m[1][1];
		result.m[1][2] = m1.m[1][2] + m2.m[1][2];
		result.m[2][0] = m1.m[2][0] + m2.m[2][0];
		result.m[2][1] = m1.m[2][1] + m2.m[2][1];
		result.m[2][2] = m1.m[2][2] + m2.m[2][2];

		return result;
	}

	Matrix &Matrix::subtract(Matrix &m1, Matrix &m2, Matrix &result)
	{
		result.m[0][0] = m1.m[0][0] - m2.m[0][0];
		result.m[0][1] = m1.m[0][1] - m2.m[0][1];
		result.m[0][2] = m1.m[0][2] - m2.m[0][2];
		result.m[1][0] = m1.m[1][0] - m2.m[1][0];
		result.m[1][1] = m1.m[1][1] - m2.m[1][1];
		result.m[1][2] = m1.m[1][2] - m2.m[1][2];
		result.m[2][0] = m1.m[2][0] - m2.m[2][0];
		result.m[2][1] = m1.m[2][1] - m2.m[2][1];
		result.m[2][2] = m1.m[2][2] - m2.m[2][2];

		return result;
	}
	
	Matrix &Matrix::multiply(Matrix &m1, Matrix &m2, Matrix &result)
	{
		result.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0];
		result.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1];
		result.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2];

		result.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0];
		result.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1];
		result.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2];

		result.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0];
		result.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1];
		result.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2];

		return result;
	}

	Matrix &Matrix::multiply(Matrix &m1, double &scale, Matrix &result)
	{
		result.m[0][0] *= scale;
		result.m[0][1] *= scale;
		result.m[0][2] *= scale;
		result.m[1][0] *= scale;
		result.m[1][1] *= scale;
		result.m[1][2] *= scale;
		result.m[2][0] *= scale;
		result.m[2][1] *= scale;
		result.m[2][2] *= scale;

		return result;
	}

	Matrix &Matrix::inverse(Matrix m1, Matrix &result)
	{
		result.m[0][0] = m1.m[0][0];
		result.m[1][0] = m1.m[0][1];
		result.m[2][0] = m1.m[0][2];
		result.m[0][1] = m1.m[1][0];
		result.m[1][1] = m1.m[1][1];
		result.m[2][1] = m1.m[1][2];
		result.m[0][2] = m1.m[2][0];
		result.m[1][2] = m1.m[2][1];
		result.m[2][2] = m1.m[2][2];

		return result;
	}

	Vector &Matrix::multiply(const Matrix &m1, const Vector &v, Vector &result)
	{
		result = Vector(

			m1.m[0][0] * v.x + m1.m[1][0] * v.y + m1.m[2][0] * v.z,
			m1.m[0][1] * v.x + m1.m[1][1] * v.y + m1.m[2][1] * v.z,
			m1.m[0][2] * v.x + m1.m[1][2] * v.y + m1.m[2][2] * v.z);

		return result;
	}

	Vector Matrix::operator*(const Vector &v) const
	{

		Vector tv;
		return multiply(*this, v, tv);

	}

}
