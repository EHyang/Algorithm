#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int maxIndex;
int minIndex;
int result;
int MM;
int NN;
void checkMinMax(int* a)
{
	int max = 0;
	int min = 101;

	for (int i = 0; i < 100; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			minIndex = i;
		}

		if (a[i] > max)
		{
			max = a[i];
			maxIndex = i;
		}
	}

	result = max - min;
	MM = max;
	NN = min;
}

int main()
{
	int box[100];
	int flat;

	for (int test = 0; test < 10; test++)
	{
		int max = 0;
		int min = 101;
		cin >> flat;
		for (int i = 0; i < 100; i++)
		{
			cin >> box[i];
			if (box[i] < min)
			{
				min = box[i];
				minIndex = i;
			}

			if (box[i] > max)
			{
				max = box[i];
				maxIndex = i;
			}
		}

		for (int i = 0; i < flat; i++)
		{
			box[minIndex]++;
			box[maxIndex]--;
			checkMinMax(box);
		}


		printf("#%d %d \n",test+1, result);
	}
}