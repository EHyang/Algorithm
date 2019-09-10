#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

string code[10] = { "0001101","0011001", "0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011" };

int num[8];
int result;

void calc(string str,int count)
{
	for (int i = 0; i < 10; i++)
	{
		if (str == code[i]) {
			num[count] = i;
			break;
		}
	}

	if (count == 0)
	{
		int sum = 0;
		int tmp;

		for (int i = 0; i < 8; i++)
		{
			sum += num[i];
		}


		tmp = ((num[0] + num[2] + num[4] + num[6]) * 3) + (num[1] + num[3] + num[5]) + num[7];

		if (tmp % 10 == 0) result = sum;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test = 1, t;

	cin >> t;

	while (t--)
	{
		int N, M;
		string str, tmp;
		cin >> N >> M;

		bool check = false;
		int ptr = -1;
		result = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> str;
			if (check) continue;

			for (int j = 0; j < M; j++)
			{
				if (str[j] == '1') ptr = j;
			}

			if (ptr != -1)
			{
				int cnt = 7;
				while (cnt >= 0)
				{
					tmp = "";
					for (int j = ptr - 6; j <= ptr; j++)
					{
						tmp += str[j];
					}

					calc(tmp, cnt--);
					ptr = ptr - 7;
				}

				check = true;
			}
		}

		cout << "#" << test++ <<" " <<result<< endl;
	}
}