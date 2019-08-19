#include <iostream>
#include <string>

using namespace std;

int main()
{
	int test;
	string re = "";
	for (int i = 1; i <= 10; i++)
	{
		string gram;
		string text;
		cin >> test;
		int count = 0;

		cin >> text;
		cin >> gram;


		while (gram.find(text) != string::npos)
		{
			int textIndex = gram.find(text, 0);
			gram.replace(textIndex, text.length(), re);
			count++;
		}

		printf("#%d %d\n", i, count);
	}
}