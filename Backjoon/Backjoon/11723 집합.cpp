#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int x;
	int bit = 0;
	string str;
	int m;

	scanf("%d", &m);

	while (m >= 1)
	{
		char ch[50];

		scanf("%s", ch);
		str = ch;

		if (str == "all") bit = (1 << 21) - 1;
		else scanf("%d", &x);

		if (str == "add") bit |= (1 << (x - 1));
		else if (str == "remove") bit &= ~(1 << (x - 1));
		else if (str == "check") (bit & (1 << (x - 1))) ? puts("1") : puts("0");
		else if (str == "toggle") bit = bit ^ (1 << (x - 1));
		else if (str == "empty") bit = 1 >> 21;
		m--;
	}

	return 0;
}