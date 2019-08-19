#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;
int limit;
int findFA(string a)
{
	int fir, co;

	fir = (int)a[0] - 48;
	co = (int)a.length();
	if (co < 2)
		limit++;
	return fir * co;
}
int main(void)
{
	int a;
	int temp;
	int check = 0;
	string number;
	string tmp;
	cin >> a;

	for (;;)
	{
		number = to_string(a);
		temp = findFA(number);
		tmp = to_string(findFA(number));
		if (temp == findFA(tmp)) {
			check = 1;
			break;
		}
		else if (limit >= 4)
			break;
		a = temp;
	}
	if (check == 1)
		cout << "FA" << endl;
	else
		cout << "NFA" << endl;

	return 0;
}