#include <iostream>
#include <deque>

using namespace std;
deque<int> rotate_queue;
deque<int> find_num;
int N, M;

void initial()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		rotate_queue.push_back(i);
	}
	int tmp;
	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		find_num.push_back(tmp);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	initial();
	int count = 0;
	int num;
	while (!find_num.empty())
	{
		int size = rotate_queue.size();;
		num = find_num.front();
		find_num.pop_front();
		int i = 0;
		for (i; rotate_queue.front() != num; i++)
		{
			rotate_queue.push_back(rotate_queue.front());
			rotate_queue.pop_front();
		}
		
		i = (size - i > i ? i : size - i);
		count += i;
		rotate_queue.pop_front();
	}

	cout << count;
}