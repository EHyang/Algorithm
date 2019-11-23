#include <iostream>
#include <vector>

#define NUMBER 1000000001
#define endl '\n'
using namespace std;

vector<int> v;

int op[4];
int op_count;
int max_num = -NUMBER;
int min_num = NUMBER;

int calc(int result, int cur, int op_add)
{
	switch (op_add)
	{
	case 0:
	{
		result += v[cur + 1];
		return result;
	}
	case 1:
	{
		result -= v[cur + 1];
		return result;
	}
	case 2:
	{
		result *= v[cur + 1];
		return result;
	}
	case 3:
	{
		result /= v[cur + 1];
		return result;
	}
	default:
		return result;
	}

	return result;
}

void copy(int *a, int *b)
{
	for (int i = 0; i < 4; i++)
	{
		b[i] = a[i];
	}
}

void DFS(int result, int cur, int count, int *op_arr)
{
	if (op_count == count)
	{
		max_num = (max_num <= result ? result : max_num);
		min_num = (min_num >= result ? result : min_num);
		return;
	}
	int op_copy[4];
	int tmp;
	for (int i = 0; i < 4; i++)
	{
		if (op_arr[i])
		{
			tmp = calc(result, cur, i);
			copy(op_arr, op_copy);
			op_copy[i]--;
			DFS(tmp, cur + 1, count + 1, op_copy);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, tmp;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
		op_count += op[i];
	}

	DFS(v[0],0, 0,op);

	cout << max_num << endl << min_num;
	return 0;
}