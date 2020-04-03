#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool check(vector<int> &A, int remove)
{
	bool up = true;
	int idx, first;

	if (remove == 0)
	{
		first = A[1];
		idx = 2;

	}
	else
	{
		first = A[0];
		idx = 1;
	}
	if (A[idx] == first) return false;
	else
	{
		if (A[idx] > first) up = true;
		else up = false;
	}

	for (int i = idx+1; i < (signed)A.size(); i++)
	{
		if (i == remove) continue;

		if (up)//rise
		{
			if (A[i] < A[i - 1])
			{
				up = false;
				continue;
			}
			else return false;
		}
		else
		{
			if (A[i] > A[i - 1])
			{
				up = true;
				continue;
			}
			else return false;
		}
	}

	return true;
}

int solution(vector<int> &A) {

	if (check(A, -1))
		return 0;

	int answer = 0;

	for (int i = 0; i < (signed)A.size(); i++)
	{
		if (check(A, i))
			answer++;
	}

	if (answer == 0) return -1;

	return answer;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<int> a = { 1,3,2,4 };
	solution(a);


	return 0;
}