#ifndef SWMATRIX_H
#define SWMATRIX_H

#include "swVector.h"

namespace SpaceWitch
{
	class Matrix
	{
	private:
		double m[3][3];
	public:
		Matrix();
		Matrix(double m00, double m01, double m02, double m10, double m11, double m12, double m20, double m21, double m22);
		Matrix(Vector m1, Vector m2, Vector m3);
		void Rot(double X, double Y, double Z);
		void Rot(Vector &v);

		double operator()(int Column, int Row) const { return m[Column][Row]; }
		double &operator()(int Column, int Row) { return m[Column][Row]; }

		static Matrix &add(Matrix &m1, Matrix &m2, Matrix &result);
		static Matrix &subtract(Matrix &m1, Matrix &m2, Matrix &result);
		static Matrix &multiply(Matrix &m1, Matrix &m2, Matrix &result);
		static Matrix &multiply(Matrix &m1, double &scale, Matrix &result);
		static Vector &multiply(const Matrix &m1, const Vector &v, Vector &result);

		Matrix &operator+=(Matrix &m) { return add(*this, m, *this); }
		Matrix &operator-=(Matrix &m) { return subtract(*this, m, *this); }
		Matrix &operator*=(Matrix &m) { Matrix tm(*this); return multiply(tm, m, *this); }
		Matrix &operator*=(double &scale) { return multiply(*this, scale, *this); }
		Vector operator*(const Vector &v) const;
		Vector mEuler(Matrix &m1);

		static Matrix &Matrix::inverse(Matrix m1, Matrix &result);
	};

}

#endif


/*Vector mEuler(Matrix33 &m)
{
	Vector v;
	float a,b,c;

	if(SQR(m(2,2)) > LimusZero)
		a = atan( m(1,2)/m(2,2) );
	else
		a = PId2;

	b = asin(-m(0,2));

	if(SQR(m(1,1)) > LimusZero)
		c = atan( m(0,1)/m(1,1) );
	else
		c = PId2;

	a = RADTODEG(a);
	b = RADTODEG(b);
	c = RADTODEG(c);

	if(m(1,1)<0)
		a = -a;
	if(m(2,1)<0)
		b = -b;
	if(m(0,1)<0)
		c = -c;


	v = Vector(a, b, c);
	return v;
}*/

/*Vector mEuler(Matrix33 &m)
{
	Vector v,t1,t2,t3;
	bool arg=false;
	float a,b,c;

	t1 = Vector(m(2,0),m(2,1),m(2,2));
	if(m(2,1)<0)
		a = acos(m(2,2)) + PI;
	else
		a = acos(m(2,2));*/

/*Vector mEuler(Matrix &m) 
{
	Vector v;
	float temp = atan2( m(0,2),m(2,2) );

	if (m(1,0) > 1 - LimusZero) // singularity at north pole
	{ 
		v = Vector(temp,PId2,0);//hab
	}
	else if (m(1,0) < LimusZero - 1) // singularity at south pole
	{
		v = Vector(temp,-PId2,0);
	}
	else
	{
		v = Vector( atan2( -m(2,0),m(0,0) ),atan2(-m(1,2),m(1,1) ),asin( m(1,0) ) );
	}
	return v;
}*/
