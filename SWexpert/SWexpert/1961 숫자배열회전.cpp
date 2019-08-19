#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<vector<int>>> result;

vector<int> tmp;
vector<vector<int>> temp;

void rotate()
{
	vector<int> ro;
	vector<vector<int>> rota;


	for (int j = 0; j < N; j++)
	{
		for (int i = N - 1; i >= 0; i--)
		{
			ro.push_back(temp[i][j]);
		}
		rota.push_back(ro);
		ro.clear();
	}
	result.push_back(rota);

	temp = rota;
}

int main()
{
	int T;

	int num;

	cin >> T;

	for (int test=0; test < T; test++) {
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> num;
				tmp.push_back(num);
			}
			temp.push_back(tmp);
			tmp.clear();
		}

		rotate();
		rotate();
		rotate();

		printf("#%d\n", test+1);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < N; k++)
				{
					printf("%d", result[j][i][k]);
				}
				printf(" ");
			}
			printf("\n");
		}
		result.clear();
		temp.clear();
		tmp.clear();
	}

	return 0;
}