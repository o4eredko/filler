#include "../includes/filler.h"

int manhattan_distance(int x1, int x2, int y1, int y2)
{
	int res;

	res = (ABS(x2 - x1)) + (ABS(y2 - y1));
	return (res);
}