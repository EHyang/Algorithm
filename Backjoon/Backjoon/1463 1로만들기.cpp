#include <stdio.h>

int main(void)
{
	int a[1000000];
	int n;
	int min = 0;
	int i;
	scanf("%d", &n);

	a[1] = 0; // 1에서 1은 연산 0번
	for (i = 2; i <= n; i++)
	{
		a[i] = a[i - 1] + 1;
		min = a[i];
		if (i % 3 == 0 && min > a[i / 3] + 1)
		{
			a[i] = a[i / 3] + 1;
			min = a[i];
		}
		if (i % 2 == 0 && min > a[i / 2] + 1)
		{
			a[i] = a[i / 2] + 1;
			min = a[i];
		}
	}
	printf("%d", min);

	return 0;
}