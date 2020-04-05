#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int m, c;
	int cns[10];
	int ms[10];
	cin >> m >> c;
	int idx = 2;
	   
	for (int i = 0; i < m; i++)
	{
		cin >> ms[i];
	}
	for (int i = 0; i < c; i++)
	{
		cns[i] = ms[i];
	}
	idx = c;
	int time = 0;
	
	while (idx<m)
	{
		for (int i = 0; i < c; i++)
		{
			if (cns[i] == 0)
			{
				cns[i] = ms[idx];
				idx++;
			}
			cns[i]--;
		}
		time++;
	}
	int modify = 0;
	for (int i = 0; i < c; i++)
	{
		modify = modify < cns[i] ? cns[i] : modify;
	}

	time += modify;
	
	cout << time;
	return 0;
}