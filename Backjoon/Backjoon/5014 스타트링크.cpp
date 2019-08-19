#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;


int main(void)
{

	int i;
	int F, S, G, U, D;
	int Stair[1000000];
	int now;
	queue <int> q;

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	for (i = 0; i < F; i++)
	{
		Stair[i] = -1;
	}
	q.push(S);

	Stair[S - 1] = 0;

	while (!q.empty())
	{
		now = q.front();
		q.pop();

		if (now + U <= F)
		{
			if (Stair[now - 1 + U] == -1)
			{
				Stair[now + U - 1] = Stair[now - 1] + 1;
				q.push(now + U);
			}
		}
		if (now - D >= 1)
		{
			if (Stair[now - 1 - D] == -1)
			{
				Stair[now - D - 1] = Stair[now - 1] + 1;
				q.push(now - D);
			}
		}
	}

	if (Stair[G - 1] == -1) printf("use the stairs");
	else printf("%d", Stair[G - 1]);

	return 0;
}