#include "swCommonMath.h"
#include "swVector.h"

namespace SpaceWitch
{
	Vector::Vector(double X, double Y, double Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	double Vector::magSqr() const
	{
		return SQR(x) + SQR(y) + SQR(z);
	}

	double Vector::mag() const
	{
		return sqrt(magSqr());
	}

	double Vector::dot(const Vector &v) const
	{
		return x*v.x + y*v.y + z*v.z;
	}

	static double dot(const Vector &v1, const Vector &v2)
	{
		return v1.dot(v2);
	}

	double Vector::dist(const Vector &v) const
	{
		return (*this - v).mag();
	}

	double Vector::distSqr(const Vector &v) const
	{
		return (*this - v).magSqr();
	}

	Vector &Vector::unit(Vector &res) const
	{
		res = Vector(*this);
		double m = res.mag();
		if (0 == m)
			return res;

		res *= 1 / m;

		return res;
	}

	Vector &Vector::add(const Vector &v1, const Vector &v2, Vector &result)
	{
		result.x = v1.x + v2.x;
		result.y = v1.y + v2.y;
		result.z = v1.z + v2.z;
		
		return result;
	}

	Vector &Vector::subtract(const Vector &v1, const Vector &v2, Vector &result)
	{
		result.x = v1.x - v2.x;
		result.y = v1.y - v2.y;
		result.z = v1.z - v2.z;
		
		return result;
	}
	
	Vector &Vector::cross(const Vector &v1, const Vector &v2, Vector &result)
	{
		result.x = v1.y * v2.z - v1.z * v2.y;
		result.y = v1.z * v2.x - v1.x * v2.z;
		result.z = v1.x * v2.y - v1.y * v2.x;

		return result;
	}

	Vector &Vector::invert(const Vector &v1, Vector &result)
	{
		result.x = -v1.x;
		result.y = -v1.y;
		result.z = -v1.z;
		
		return result;
	}

	Vector &Vector::multiply(const Vector &v1, const double &scale, Vector &result)
	{
		result.x = v1.x * scale;
		result.y = v1.y * scale;
		result.z = v1.z * scale;
		
		return result;
	}

}