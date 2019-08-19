#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int log;
	string name, inout;
	
	cin >> log;

	set<string> human;
	set<string>::reverse_iterator h;
	for (int i = 0; i < log; i++)
	{
		cin >> name >> inout;

		if (inout[0] == 'e')
		{
			human.insert(name);
		}
		else if (inout[0] == 'l')
		{
			human.erase(name);
		}
		fflush(stdin);
	}

	for (h = human.rbegin(); h != human.rend(); h++)
	{
		cout << *h << "\n";
	}
}