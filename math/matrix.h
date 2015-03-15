#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

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

		static Matrix &inverse(Matrix m1, Matrix &result);
	};

}

#endif
