#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	string ans;
	cin >> N;

	if (N % 2 == 0)
	{
		for (int i = 0; i < N / 2; i++)
		{
			ans += "1";
		}
	}
	else
	{
		ans += "7";
		for (int i = 0; i < N / 2 - 1; i++)
			ans += "1";
	}

	cout << ans;
	
	return 0;
}