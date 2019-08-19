#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int temp;


	cin >> N;


	for (int i = 1; i <= N; i++)
	{
		int num = i;
		int count = 0;
		if (num > 100)
		{
			if ((num / 100) % 3 == 0)
			{
				count++;
			}
			num = num % 100;
		}
		if (num > 10)
		{
			if ((num / 10) % 3 == 0)
			{
				count++;
			}
			num = num % 10;
		}
		if (num!=0 && num % 3 == 0)
			count++;


		if (count == 3)
			printf("--- ");
		else if (count == 2)
			printf("-- ");
		else if (count == 1)
			printf("- ");
		else
			printf("%d ",i);
	}

	return 0;
}