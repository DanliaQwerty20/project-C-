#pragma once
#include<math.h>
#include <stdio.h>
class kpur
{
private:
	int r, x, y;

public:
	void tohka();
	kpur();
	int operator / (kpur kpur2)
	{
		double n = (sqrt((x - kpur2.x) + (y - kpur2.y)));
		if ((r - kpur2.r) < n < (r + kpur2.r))
			printf("peresek");
		else
			printf(" ne peresek");

		return 0;
	}
};