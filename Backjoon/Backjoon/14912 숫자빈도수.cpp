#include <iostream>
#include <string>
using namespace std;


int find(string a, int num)
{
	int count = 0;
	int i;

	for (i = 0; i < (int)a.length(); i++)
	{
		if (a[i] == (char)(num + 48))
		{
			count++;
		}
	}

	return count;
}

int main() {

	int a, i;
	int num;
	string all;
	string temp;
	cin >> a;
	cin >> num;
	for (i = 1; i <= a; i++)
	{
		temp = to_string(i);

		all = all.append(temp);
	}

	cout << find(all, num);

	return 0;
}