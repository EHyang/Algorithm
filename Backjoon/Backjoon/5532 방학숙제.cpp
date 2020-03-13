#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int L, A, B, C, D;

	cin >> L >> A >> B >> C >> D;

	int answer = 0;

	if (A%C == 0) answer = A / C;
	else if (A%C >= 1) answer = A / C + 1;

	if (B%D == 0) answer = (answer >= B / D ? answer : B / D);
	else if (B%D >= 1) answer = (answer >= B / D + 1 ? answer : B / D + 1);

	cout << L - answer;

	return 0;
}