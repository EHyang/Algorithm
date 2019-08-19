#include <stdio.h>

int main(void)
{
	int arr[1000];
	int arr2[1000];
	int n;
	int max = 0;
	int i, j;
	arr[0] = 0;
	arr2[0] = 0;
	scanf("%d", &n); // 상자의 개수 입력

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]); // 각 상자들의 크기 입력
	}

	for (i = 1; i <= n; i++)
	{
		arr2[i] = 1; // 상자가 들어가는 최솟값
		for (j = i - 1; j > 0; j--)
		{
			if (arr[i] > arr[j]) {
				if (arr2[j] + 1 > arr2[i])
					arr2[i] = arr2[j] + 1;
			}
			if (arr2[i] > max)
			{
				max = arr2[i];
			}
		}
	}
	printf("%d", max);

	return 0;
}

