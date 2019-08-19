#include <iostream>

using namespace std;
int N, M;
int result;
void my_pow(int x,int y,int count)
{
	if (count == M)
		return;
	result = x * y;

	my_pow(result, y, ++count);
}


int pp(int a)
{
	return pp_tail(a,a,1);
}

int pp_tail(int x, int y, int count)
{
	if (count == M) return x * y;
	return pp_tail(x*y, y, ++count);
}



int main()
{
	for (int t = 1; t <= 10; t++)
	{
		int temp;

		cin >> temp >> N >> M;
		//my_pow(N, N, 1);
		printf("#%d %d\n", t, pp(N));
	}
}