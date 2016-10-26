#include <stdio.h>
const int NO_REPEAT_FLAG = -1;
void Swap(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}
//Like radix_sort, find the first repeating number
int RadixSort(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		while (i != a[i])
		{
			if (a[i] == a[a[i]])
				return a[i];
			Swap(a[i], a[a[i]]);
		}
	}
	return NO_REPEAT_FLAG;
}
void PrintfArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}
int main()
{
	const int MAXN = 10;
	int a[MAXN] = {2, 4, 1, 5, 7,  6, 1, 9, 0, 2};
	//int a[MAXN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	PrintfArray(a, MAXN);

	int nRepeatNumber = RadixSort(a, MAXN);
	if (nRepeatNumber != NO_REPEAT_FLAG)
		printf("%d\n", nRepeatNumber);
	else
		printf("No repeating number\n");

	return 0;
}
