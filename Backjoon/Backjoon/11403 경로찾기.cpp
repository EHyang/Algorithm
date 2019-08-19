#include <iostream>
#include <queue>

using namespace std;
int N;
int input[100][100];
int result[100][100];

void dfs(int i,int j)
{
	if (result[i][j] == 1) return;
	
	result[i][j] = 1;

	for (int k = 0; k < N; k++)
	{
		if (input[j][k] == 1)
			dfs(i, k);
	}
}

int main()
{	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (input[i][j] == 1)
			{
				dfs(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << result[i][j] <<" ";
		}
		cout << endl;
	}
	return 0;
}