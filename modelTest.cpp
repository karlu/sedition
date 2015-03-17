#include "swmodel.h"

#include <iostream>

using namespace std;
using namespace SpaceWitch;

int main()
{
	Vector v1(1,0,1);
	Vector v2(2,1,0);

	Vector v3 = v1+v2;
	Triangle t(v1,v2,v3);
	if(v3.x != 3 || v3.y != 1 || v3.z != 1)
	{
		cout << "Vector addition error\n";
		return -1;
	}

	cout << "Model test passed!\n";

	return 0;
}
