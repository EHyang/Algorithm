#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> r;
int N, temp;
int k = 0, nk = 0;
int a, b;

bool re()
{
	for (int i = 0; i < N; i++)
	{
		if (v[i] == (N - i)) continue;
		else return false;
	}

	return true;
}

void find()
{
	for (int i = 0; i < N - 1; i++)
	{
		if (v[i] != 1 && v[i] != N)
		{
			if (v[i + 1] != v[i] + 1 && v[i + 1] != v[i] - 1)
			{
				int j = i + 1;
				int nj = j + 1;
				int plusv = v[j] + 1;
				int minusv = v[j] - 1;

				if (nj == N) nj = 0;
				if (plusv > N) plusv = 1;
				if (minusv == 0) minusv = N;

				if (plusv == v[nj]) b = i;
				else if (minusv == v[nj]) a = j;
			}
		}
		else if (v[i] == 1)
		{
			if (v[i + 1] != 2 && v[i + 1] != 10)
			{
				int j = i + 1;
				int nj = j + 1;
				int plusv = v[j] + 1;
				int minusv = v[j] - 1;
				
				if (nj == N) nj = 0;
				if (plusv > N) plusv = 1;
				if (minusv == 0) minusv = N;

				if (plusv == v[nj]) b = i;
				else if (minusv == v[nj]) a = j;
			}
		}
		else if (v[i] == N)
		{
			if (v[i + 1] != 1 && v[i + 1] != N - 1)
			{
				int j = i + 1;
				int nj = j + 1;
				int plusv = v[j] + 1;
				int minusv = v[j] - 1;

				if (nj == N) nj = 0;
				if (plusv > N) plusv = 1;
				if (minusv == 0) minusv = N;

				if (plusv == v[nj]) b = i;
				else if (minusv == v[nj]) a = j;
			}
		}
	}
}

void right()
{
	vector<int>::iterator itr;
	itr = v.begin();
	
	v.insert(itr, *(v.end()-1));
	v.erase(v.end() - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	if (re())
	{
		k = N - 1;
		nk = N - 1;
		a = 0;
		b = N-1;
	}
	else
	{
		find();

		for (; a != 0;)
		{
			right();
			k++;
			a++;
			b++;
			if (a == N) a = 0;
			if (b == N) b = 0;
		}
		
		reverse(v.begin(), v.begin() + (b + 1));

		for (; v[0] != 1;)
		{
			right();
			nk++;
		}
	}
	   
	cout << nk << endl << a+1 << " " << b+1 << endl << k;

	return 0;
}