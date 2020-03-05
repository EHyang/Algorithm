#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 1;

	for (; n / 2 > 0;)
	{
		ans += n % 2;
		n /= 2;
	}

	return ans;
}