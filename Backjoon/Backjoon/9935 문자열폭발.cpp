#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string a, b;

	cin >> a >> b;

	int idx = 0;
	char answer[1000001];
	bool ch = false;

	for (int i = 0; i < a.size(); i++)
	{
		ch = false;
		answer[idx] = a[i];
		int bomb_idx = b.size() - 1;
		int size = b.size();
		if (a[i] == b[bomb_idx])
		{
			for (int j = idx; j > (idx - size); j--)
			{
				if (answer[j] == b[bomb_idx])
				{
					ch = true;
					bomb_idx--;
				}
				else
				{
					ch = false;
					break;
				}
			}
		}
		if (ch)
		{
			idx -= (b.size() - 1);
		}
		else idx++;
	}

	if (!idx)
		cout << "FRULA" << endl;
	else
	{
		for (int i = 0; i < idx; i++)
		{
			cout << answer[i];
		}
	}

	return 0;
}