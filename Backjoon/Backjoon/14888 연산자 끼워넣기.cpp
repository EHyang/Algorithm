//#include <iostream>
//#include <vector>
//
//#define NUMBER 1000000001
//#define endl '\n'
//using namespace std;
//
//vector<int> v;
//
//int op[4];
//int op_count;
//int max_num = -NUMBER;
//int min_num = NUMBER;
//
//int calc(int result, int cur, int op_add)
//{
//	switch (op_add)
//	{
//	case 0:
//	{
//		result += v[cur + 1];
//		return result;
//	}
//	case 1:
//	{
//		result -= v[cur + 1];
//		return result;
//	}
//	case 2:
//	{
//		result *= v[cur + 1];
//		return result;
//	}
//	case 3:
//	{
//		result /= v[cur + 1];
//		return result;
//	}
//	default:
//		return result;
//	}
//
//	return result;
//}
//
//void copy(int *a, int *b)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		b[i] = a[i];
//	}
//}
//
//void DFS(int result, int cur, int count, int *op_arr)
//{
//	if (op_count == count)
//	{
//		max_num = (max_num <= result ? result : max_num);
//		min_num = (min_num >= result ? result : min_num);
//		return;
//	}
//	int op_copy[4];
//	int tmp;
//	for (int i = 0; i < 4; i++)
//	{
//		if (op_arr[i])
//		{
//			tmp = calc(result, cur, i);
//			copy(op_arr, op_copy);
//			op_copy[i]--;
//			DFS(tmp, cur + 1, count + 1, op_copy);
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	int N, tmp;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		cin >> tmp;
//		v.push_back(tmp);
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		cin >> op[i];
//		op_count += op[i];
//	}
//
//	DFS(v[0],0, 0,op);
//
//	cout << max_num << endl << min_num;
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> oper;

int num[12];
int op[4];
int min_va = INT32_MAX;
int max_va = -INT32_MAX;

int solve(int val,int idx,int o)
{
	switch (o)
	{
	case 0:
		val += num[idx];
		return val;
	case 1:
		val -= num[idx];
		return val;
	case 2:
		val *= num[idx];
		return val;
	case 3:
		val /= num[idx];
		return val;
	default:
		break;
	}
}

void calc() {
	do {
		int idx = 1;
		int value;
		value = solve(num[0], idx++, oper[0]);
		for (int i = 1; i < oper.size(); i++)
		{
			value = solve(value, idx++, oper[i]);
		}
		min_va = min(min_va, value);
		max_va = max(max_va, value);
	} while (next_permutation(oper.begin(), oper.end()));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	}

	for (int i = 0; i < 4; i++)
	{
		while (op[i] != 0)
		{
			oper.push_back(i);
			op[i]--;
		}
	}
	calc();

	cout << max_va << endl << min_va;


	return 0;
}
