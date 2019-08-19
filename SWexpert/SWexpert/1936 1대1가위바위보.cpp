#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;

	//switch (a)
	//{
	//case 1:
	//	if (b == 2)
	//		printf("B");
	//	if (b == 3)
	//		printf("A");
	//case 2:
	//	if (b == 1)
	//		printf("A");
	//	if (b == 3)
	//		printf("B");
	//case 3:
	//	if (b == 1)
	//		printf("B");
	//	if (b == 2)
	//		printf("A");
	//}

	if (a - b == 1 || a - b == -2)
		printf("A");
	else
		printf("B");

	return 0;
}