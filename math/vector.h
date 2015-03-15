#ifndef VECTOR_H
#define VECTOR_H

namespace SpaceWitch
{
	class Vector
	{
	public:
		double x, y, z;

		Vector() : x(0.0), y(0.0), z(0.0) {}
		Vector(double x, double y, double z);

		void reset() { x = 0.0, y = 0.0, z = 0.0; }

		double mag() const;
		double magSqr() const;

		double dot(const Vector &v) const;
		static double dot(const Vector &v1, const Vector &v2);

		double dist(const Vector &v) const;
		double distSqr(const Vector &v) const;

		Vector &unit(Vector &res) const;

		static Vector &add(const Vector &v1, const Vector &v2, Vector &result);
		static Vector &subtract(const Vector &v1, const Vector &v2, Vector &result);
		static Vector &cross(const Vector &v1, const Vector &v2, Vector &result);
		static Vector &invert(const Vector &v1, Vector &result);
		static Vector &multiply(const Vector &v1, const double &scale, Vector &result);

		Vector operator-() const { return Vector(-x,-y,-z); }
		Vector &operator+=(const Vector &v) { return add(*this, v, *this); }
		Vector &operator-=(const Vector &v) { return subtract(*this, v, *this); }
		Vector &operator*=(const Vector &v) { Vector tv(*this); return cross(tv, v, *this); }
		Vector &operator*=(const double &scale) { return multiply(*this, scale, *this); }
		Vector operator+(const Vector &v) const { Vector tv; return add(*this, v, tv); }
		Vector operator-(const Vector &v) const { Vector tv; return subtract(*this, v, tv); }
		Vector operator*(const Vector &v) const { Vector tv; return cross(*this, v, tv); }
		Vector operator*(const double &scale) const { Vector tv; return multiply(*this, scale, tv); }

	};

}

#endif


/*

class Vector
{
public:
enum Status { INVALID, DEFAULT, UNIT };

private:
double _x, _y, _z;
Status _Status;

Vector(double x, double y, double z, Status s) : _x(x), _y(y), _z(z), _Status(s) {}

public:

Vector() : _x(0.0), _y(0.0), _z(0.0), _Status(INVALID) {}
Vector(double x, double y, double z);

double X() const { return _x; }
double Y() const { return _y; }
double Z() const { return _z; }
int isUnit() const { return _Status == UNIT; }
int isDefault() const { return _Status == DEFAULT; }
int isValid() const { return _Status != INVALID; }

Vector &unit();
static Vector &unit(const Vector &v, Vector &result) { result = v; return result.unit(); }
static Vector unit(const Vector &v) { return Vector(v).unit(); }

Vector &Default();
static Vector Default(const Vector &v, Vector &result) { result = v; return result.Default(); }
static Vector Default(const Vector &v) { return Vector(v).Default(); }

double mag() const { return (isValid() ? (isUnit() ? 1.0 : sqrt(sqr(X()) + sqr(Y()) + sqr(Z()))) : 0.0); }
double magSqr() const { return (isValid() ? (isUnit() ? 1.0 : sqr(X()) + sqr(Y()) + sqr(Z())) : 0.0); }

double dot(const Vector &v) const { return ((isValid() && v.isValid()) ? (X()*v.X() + Y()*v.Y() + Z()*v.Z()) : 0.0); }
static double dot(const Vector &v1, const Vector &v2) { return v1.dot(v2); }

double dist(const Vector &v) const { return (*this - v).mag(); }
double distSqr(const Vector &v) const { return (*this - v).magSqr(); }

static Vector &add(const Vector &v1, const Vector &v2, Vector &result);
static Vector &subtract(const Vector &v1, const Vector &v2, Vector &result);
static Vector &cross(const Vector &v1, const Vector &v2, Vector &result);
static Vector &invert(const Vector &v1, Vector &result);
static Vector &multiply(const Vector &v1, const double &scale, Vector &result);

Vector operator-() const { return invert(*this, Vector()); }
Vector &operator+=(const Vector &v) { return add(*this, v, *this); }
Vector &operator-=(const Vector &v) { return subtract(*this, v, *this); }
Vector &operator*=(const Vector &v) { Vector tv(*this); return cross(tv, v, *this); }
Vector &operator*=(const double &scale) { return multiply(*this, scale, *this); }
Vector operator+(const Vector &v) const { Vector tv; return add(*this, v, tv); }
Vector operator-(const Vector &v) const { Vector tv; return subtract(*this, v, tv); }
Vector operator*(const Vector &v) const { Vector tv; return cross(*this, v, tv); }
Vector operator*(const double &scale) const { Vector tv; return multiply(*this, scale, tv); }
};

*/
