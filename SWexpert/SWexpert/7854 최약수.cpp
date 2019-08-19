#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<long long> num = { 1,2,5,10,20,25,50,100 };

void cal(int p)
{
	int plus[5] = { 125,200,250,500,1000 };
	for (int i = 0; i < 5; i++)
	{
		num.push_back(plus[i] * pow(10,p));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	long long goal;
	long long c=0;
	int po = 0;
	cin >> t;
	int Test = 1;
	while (t--)
	{
		cin >> goal;
		if (num.back() > goal)
		{
			for (int i = 0;i<num.size(); i++)
			{
				if (num[i] <= goal) c++;
				else break;
			}
		}
		else
		{
			while (num.back() < goal)
			{
				cal(po++);
			}

			for (int i = 0; i<num.size(); i++)
			{
				if (num[i]<= goal) c++;
				else break;
			}
		}

		cout << "#" << Test++ << " " << c << endl;
		c = 0;
	}
}