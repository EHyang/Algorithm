/*

vector<int> a[100];

a[i].push_back(n);

*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<queue<string>> human;
queue<string> in;

vector<int> age;

int main()
{
	int N;
	int input_age;
	string input_name;
	human.assign(100001, in);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> input_age >> input_name;

		age.push_back(input_age);
		human[input_age].push(input_name);
	}

	sort(age.begin(), age.end());

	for (int i = 0; i < N; i++)
	{
		cout << age[i] << ' ' << human[age[i]].front() << '\n';
		human[age[i]].pop();
	}


	return 0;
}