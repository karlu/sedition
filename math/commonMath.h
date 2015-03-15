#ifndef COMMONMATH_H
#define COMMONMATH_H

#include <math.h>

const float PI       =  3.14159265358979323846f;
const float PI2		 =	6.28318530717958647693f;
const float PId2	 =	1.57079632679489661923f;


#define LimusZero 1.0e-8

#define	DEGTORAD(x)	( ((x) * PI) / 180.0 )
#define	RADTODEG(x)	( ((x) * 180.0) / PI )

#define	SQR(x)		( (x) * (x) )

/*template <class T> inline T sqr(const T &x)
{
	return x*x;
}*/

// limits a value to low and high
#define LIMIT_RANGE(low, value, high)	{	if (value < low)	value = low;	else if(value > high)	value = high;	}

//void SWAP(float &x, float &y) {	float temp;	temp = x;	x = y;	y = temp;	}

#endif
