#include <iostream>

using namespace std;

long long solution(int w, int h)
{
	long long answer = 0;

	for (long long i = 0; i < w; i++)
	{
		answer += (long long)(i*h/w);
	}

	answer *= 2;
	return answer;
}
int main()
{
	cout << solution(100000000, 100000000);

	return 0;
}