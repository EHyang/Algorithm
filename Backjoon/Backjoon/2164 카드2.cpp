#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	queue<int> card;
	queue<int> trash;

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		card.push(i);
	}

	while (card.size() != 1)
	{
		trash.push(card.front());
		card.pop();
		card.push(card.front());
		card.pop();
	}

	cout << card.front();

}