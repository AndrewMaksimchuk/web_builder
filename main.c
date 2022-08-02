#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declaration
int myFunction(int, int);

int main()
{

	char leftTop[] = "\u2554";
	char top[] = "\u2550";
	char rightTop[] = "\u2557";

	printf("%s", leftTop);

	int count = 50;
	int* pcount = &count;

	for (int i = 0; i < count; ++i)
	{
		printf("%s", top);
	}

	printf("%s\n", rightTop);

	*pcount = 100;

	printf("%i\n", count);
	printf("%i\n", *pcount);

	return 0;
}

// Function definition
int myFunction(int x, int y) {
  return x + y;
}


/*

Table structure

table = [
	1, 2, 3, 4, 5, 6, 7, 8,
	a, b, c, d, e, f, g, h,
]

*/