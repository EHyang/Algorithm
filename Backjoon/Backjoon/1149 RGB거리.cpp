#include <stdio.h>

int MinCheck(int num1, int num2)
{
	if (num1 > num2) return num2;
	else return num1;
}

int Min(int num1, int num2, int num3)
{
	int min;

	if (num2 > num1) min = num1;
	else min = num2;
	if (min > num3) min = num3;

	return min;
}

int main(void)
{
	int a[1000][3] = { 0 };
	int c[1000][3] = { 0 };
	int i, n, r, g, b;
	int min;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &r, &g, &b);
		c[i][0] = r;
		c[i][1] = g;
		c[i][2] = b;
	}
	//for (i = 1; i <= n; i++)
	//{
	//	printf("%d , %d , %d\n", c[i][0], c[i][1], c[i][2]);
	//}
	a[1][0] = c[1][0];
	a[1][1] = c[1][1];
	a[1][2] = c[1][2];
	for (i = 2; i <= n; i++)
	{
		a[i][0] = MinCheck(a[i - 1][1], a[i - 1][2]) + c[i][0];
		a[i][1] = MinCheck(a[i - 1][0], a[i - 1][2]) + c[i][1];
		a[i][2] = MinCheck(a[i - 1][0], a[i - 1][1]) + c[i][2];

		//printf("%d , %d , %d\n", a[i][0], a[i][1], a[i][2]);
	}

	min = Min(a[n][0], a[n][1], a[n][2]);

	printf("%d", min);

	return 0;
}