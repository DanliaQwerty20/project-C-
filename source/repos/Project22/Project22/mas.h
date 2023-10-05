#pragma once
#include <stdio.h>
#include <iostream>
#include<math.h>
class mas
{
private:
	int r, x, y;
	double d1;
public:
	void tohka();
	
	mas();
	int operator / (mas kpur2)
	{
		d1 = sqrt(pow(x - kpur2.x, 2) + pow(y - kpur2.y, 2));
		if (d1 > kpur2.r + r || d1 < abs(r - kpur2.r)) {
			printf("Не пересекаются");
		}
		else {
			printf("Пересекаются");
		}
		return 0;
	}

};
