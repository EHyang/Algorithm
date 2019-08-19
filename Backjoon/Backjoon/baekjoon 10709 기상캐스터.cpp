#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int H, W;
	char tmp;

	int check = 0; // 전에 C를 만났으면 1, 안만났으면 0;
	int time = 0;

	vector<vector <char>> cloud;
	vector<char> clo;

	vector<vector <int>> result;
	vector<int> re;


	cin >> H >> W;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> tmp;
			clo.push_back(tmp);
		}
		cloud.push_back(clo);
		clo.clear();
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (cloud[i][j] == '.' && check == 0)
				time = -1;
			if (cloud[i][j] == 'c')
			{
				time = 0; check = 1;
			}
			if (cloud[i][j] == '.' && check == 1)
			{
				time++;
			}

			re.push_back(time);
		}

		result.push_back(re);
		re.clear();
		time = 0;
		check = 0;
	}


	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}