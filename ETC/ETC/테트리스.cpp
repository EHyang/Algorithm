#include <iostream>
#include <string>
#include <memory>
using namespace std;

int tmp[13][9] = { 0 };
int answer[13][9] = { 0 };

void check_block(char a, int dot, int line, int field[13][9])
{
	switch (a)
	{
	case 'A':
	{
		field[line][dot] = 1;
		field[line][dot + 1] = 1;
		field[line][dot + 2] = 1;
		field[line][dot + 3] = 1;
		break;
	}
	case 'B':
	{
		field[line - 1][dot] = 1;
		field[line - 1][dot + 1] = 1;
		field[line - 1][dot + 2] = 1;
		field[line][dot + 1] = 1;
		break;
	}
	case 'C':
	{
		field[line - 1][dot] = 1;
		field[line - 1][dot + 1] = 1;
		field[line][dot] = 1;
		field[line][dot + 1] = 1;
		break;
	}
	case 'D':
	{
		field[line - 1][dot] = 1;
		field[line - 1][dot + 1] = 1;
		field[line][dot + 1] = 1;
		field[line][dot + 2] = 1;
		break;
	}
	case 'E':
	{
		field[line - 1][dot + 1] = 1;
		field[line - 1][dot + 2] = 1;
		field[line][dot] = 1;
		field[line][dot + 1] = 1;
		break;
	}
	case 'F':
	{
		field[line - 1][dot] = 1;
		field[line - 1][dot + 1] = 1;
		field[line - 1][dot + 2] = 1;
		field[line][dot + 2] = 1;
		break;
	}
	case 'G':
	{
		field[line - 1][dot + 2] = 1;
		field[line][dot] = 1;
		field[line][dot + 1] = 1;
		field[line][dot + 2] = 1;
		break;
	}
	}
}

int main()
{
	string input;
	char block;
	int dot, l;
	getline(cin, input);
	for (int i = 0; i < input.size(); i += 3)
	{
		if (65 <= input[i] && input[i] <= 90)
		{
			block = input[i];
		}
		if (48 <= input[i + 1] && input[i + 1] <= 57)
		{
			dot = input[i + 1] - '0';
		}
		bool check = false;
		for (int f = 0; f < 12; f++)
		{
			memset(tmp, 0, sizeof(tmp));
			check_block(block, dot, f, tmp);
			for (int j = 0; j < 12; j++)
			{
				for (int k = 1; k <= 8; k++)
				{
					if (tmp[j][k] == 1 && answer[j][k] == 1)
					{
						check = true;
					}
				}
			}
			if (!check) l = f;
			else {
				l = f - 1;
				break;
			}
		}
		check_block(block, dot, l, answer);

	}

	for (int i = 0; i < 12; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if (answer[i][j] == 1)
				cout << "бр ";
			else cout << ".. ";
		}
		cout << endl;
	}

	return 0;
}