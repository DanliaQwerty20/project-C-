
#pragma once
#include "mas.h"
#include<stdio.h>
#include<math.h>
void mas::tohka()
{
	int i, j;
	double n;
	i = x;
	j = y;
	n = sqrt(((i - 0) * (i - 0)) + ((j - 0) * (j - 0)));
	if (n <= r)
	{
		printf("prinadlezit\n");
	}
	else
	{
		printf("ne_prinadlezit\n");
	}
}
mas::mas()
{
	printf("vvedite r\n");
	scanf_s("%d", &r);
	printf("vvedite x, y\n");

	scanf_s(" %d %d", &x, &y);
}

