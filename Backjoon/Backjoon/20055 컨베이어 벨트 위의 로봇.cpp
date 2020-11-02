#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

queue<int> robot;
vector<int> belt;
vector<int> empt;

int N, K, tmp;
int upsite = 1, downsite;
int cnt = 0, answer = 0;

void init()
{
    belt.push_back(0);
    empt.push_back(0);
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> tmp;
        belt.push_back(tmp);
        empt.push_back(0);
    }
}

void rotate()
{
    int f;
    tmp = *(belt.end() - 1);
    belt.pop_back();
    belt.insert(belt.begin() + 1, tmp);

    tmp = *(empt.end() - 1);
    empt.pop_back();
    empt.insert(empt.begin() + 1, tmp);

    for (int i = 0; i < robot.size(); i++)
    {
        f = robot.front();
        robot.pop();
        f = f + 1 > 2 * N ? 1 : f + 1;
        robot.push(f);
    }
}

void move_robot()
{
    int c = robot.size();
    int r, nr;

    for (int i = 0; i < c; i++)
    {
        r = robot.front();
        robot.pop();

        nr = r + 1 > 2 * N ? 1 : r + 1;

        if (r == downsite)
        {
            empt[r] = 0;
            continue;
        }
        else
        {
            if (belt[nr] >= 1 && empt[nr] == 0)
            {
                belt[nr]--;
                if (belt[nr] == 0)
                    cnt++;
                empt[r] = 0;
                if (nr == downsite)
                    continue;

                empt[nr] = nr;
                robot.push(nr);
            }
            else
            {
                robot.push(r);
            }
        }
    }
}

void input_robot()
{
    if (empt[1] == 0 && belt[1] >= 1)
    {
        robot.push(1);
        belt[1]--;
        empt[1] = 1;
        if (belt[1] == 0)
            cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    downsite = N;

    init();

    while (cnt < K)
    {
        answer++;
        rotate();
        move_robot();
        input_robot();
    }

    cout << answer;
    
    return 0;
}