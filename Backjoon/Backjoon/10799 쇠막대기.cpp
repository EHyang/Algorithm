#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string input;
	int result = 0;
	int L_count = 0;
	bool Left = false;

	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			L_count++;
			Left = true;
		}
		
		else if (input[i] == ')')
		{
			L_count--;
			if (Left)
			{
				result += L_count;
				Left = false;
			}
			else
			{
				result++;
			}
		}
	}
	cout << result;
	return 0;
}
