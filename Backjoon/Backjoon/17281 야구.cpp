#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int p[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int ining[51][10];
int N;

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> ining[i][j];
        }
    }
}

int playGame(int a[8])
{
    int result = 0;
    int player[10];

    for (int i = 0; i < 9; i++)
    {
        int j = i;
        if (i == 3)
        {
            player[i] = 1;
            continue;
        }
        if (i > 3)
        {
            j = i - 1;
        }
        player[i] = a[j];
    }

    int curPlayer = 0;

    for (int k = 0; k < N; k++)
    {
        int base[4] = {0, 0, 0, 0};
        // queue<int> inGame;
        int outCount = 0;
        while (outCount < 3)
        {
            int nowPlay = ining[k][player[curPlayer]];

            curPlayer++;
            if (curPlayer == 9)
                curPlayer = 0;

            // if (nowPlay == 0)
            // {
            //     outCount++;
            //     continue;
            // }
            // else
            // {
            //     for (int i = 0; i < 4; i++)
            //     {
            //         if (base[i])
            //     }
            // }

            switch (nowPlay)
            {
            case 0:
                outCount++;
                break;
            case 1:
                result += base[3];
                base[3] = base[2];
                base[2] = base[1];
                base[1] = 1;
                break;
            case 2:
                result += base[3];
                result += base[2];
                base[3] = base[1];
                base[2] = 1;
                base[1] = 0;
                break;
            case 3:
                result += base[3];
                result += base[2];
                result += base[1];
                base[3] = 1;
                base[2] = 0;
                base[1] = 0;
                break;
            case 4:
                result += base[3];
                result += base[2];
                result += base[1];
                result += 1;
                base[3] = 0;
                base[2] = 0;
                base[1] = 0;
                break;
            default:
                break;
            }

            // while (inGame.size() > 3)
            // {
            //     if (inGame.front() == 1)
            //     {
            //         result++;
            //     }

            //     inGame.pop();
            // }
        }
    }
    return result;
}

void solve()
{
    int maxResult = -1;

    do
    {
        int res = playGame(p);
        maxResult = maxResult < res ? res : maxResult;
    } while (next_permutation(p, p + 8));

    cout << maxResult;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();

    return 0;
}