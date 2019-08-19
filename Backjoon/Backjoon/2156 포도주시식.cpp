#include <stdio.h>

int main(void)
{
	int i;

	int value[10001] = { 0 };
	int dp[10001];
	int N;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &value[i]);
	}

	dp[0] = 0;
	dp[1] = value[1];
	dp[2] = value[1] + value[2];

	for (i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1];

		if (dp[i] < dp[i - 2] + value[i])
		{
			dp[i] = dp[i - 2] + value[i];
		}
		if (dp[i] < dp[i - 3] + value[i - 1] + value[i])
		{
			dp[i] = dp[i - 3] + value[i - 1] + value[i];
		}
	}

	printf("%d", dp[N]);

	return 0;
}