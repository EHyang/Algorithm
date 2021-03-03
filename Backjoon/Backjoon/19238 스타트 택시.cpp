#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

/*
전형적인 bfs 문제인듯 하다.

1. init
2. 현위치에서 가장가까운 승객 위치 스캔
3. 승객의 목적지까지 최단거리 검색
4. 연료 계산
5. 2~4 반복.

*/

struct passenger
{
    int x;
    int y;
    int des_x;
    int des_y;
};

struct mapInfo
{
    int num;
    int x;
    int y;
    int cnt;
    int fuel;
};

int map[21][21];

int visit[21][21];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int N, M, fuel;
int taxi_x, taxi_y;

bool available = false;

vector<mapInfo> passengerInfo;

passenger p[401];

bool check(int a, int b)
{
    return (a <= N && a >= 1 && b <= N && b >= 1);
}

bool closePassenger(mapInfo a, mapInfo b)
{
    if (a.cnt <= b.cnt)
    {
        if (a.cnt == b.cnt)
        {
            if (a.x <= b.x)
            {
                if (a.x == b.x)
                {
                    if (a.y < b.y)
                    {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void init()
{
    cin >> N >> M >> fuel;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];

            // 벽
            if (map[i][j] == 1)
                map[i][j] = -1;
        }
    }

    cin >> taxi_x >> taxi_y;

    for (int i = 1; i <= M; i++)
    {
        cin >> p[i].x >> p[i].y >> p[i].des_x >> p[i].des_y;

        // 승객 위치
        map[p[i].x][p[i].y] = i;
        // map[p[i].des_x][p[i].des_y] = i;
    }
}

void findPassenger()
{
    memset(visit, 0, sizeof(visit));

    queue<mapInfo> q;

    mapInfo m;

    m.x = taxi_x;
    m.y = taxi_y;
    m.cnt = 0;
    m.fuel = fuel;

    q.push(m);

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        int leftFuel = q.front().fuel;

        if (visit[x][y] != 0)
        {
            q.pop();
            continue;
        }

        visit[x][y] = 1;
        if (map[x][y] != 0)
        {
            q.front().num = map[x][y];
            passengerInfo.push_back(q.front());
        }

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check(nx, ny) && visit[nx][ny] == 0 && map[nx][ny] != -1)
            {
                mapInfo ma;
                ma.x = nx;
                ma.y = ny;
                ma.cnt = cnt + 1;
                ma.fuel = leftFuel - 1;
                q.push(ma);
            }
        }
    }
}

void findPath()
{
    memset(visit, 0, sizeof(visit));

    queue<mapInfo> q;

    int d_x = p[passengerInfo[0].num].des_x;
    int d_y = p[passengerInfo[0].num].des_y;
    map[passengerInfo[0].x][passengerInfo[0].y] = 0;

    passengerInfo[0].cnt = 0;
    q.push(passengerInfo[0]);

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        int leftFuel = q.front().fuel;

        q.pop();

        if (visit[x][y] != 0)
            continue;

        visit[x][y] = 1;

        if (x == d_x && y == d_y)
        {
            taxi_x = x;
            taxi_y = y;
            fuel = leftFuel + (cnt * 2);
            available = true;
            break;
        }
        if (leftFuel == 0)
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check(nx, ny) && visit[nx][ny] == 0 && map[nx][ny] != -1)
            {
                mapInfo ma;
                ma.x = nx;
                ma.y = ny;
                ma.cnt = cnt + 1;
                ma.fuel = leftFuel - 1;
                q.push(ma);
            }
        }
    }
}

void solve()
{
    for (int i = 0; i < M; i++)
    {
        findPassenger();
        if (i == 0)
        {
            if (passengerInfo.size() == 0)
            {
                cout << "-1" << endl;
                return;
            }

            else if (passengerInfo.size() != M)
            {
                cout << "-1" << endl;
                return;
            }
        }
        sort(passengerInfo.begin(), passengerInfo.end(), closePassenger);
        findPath();

        if (!available)
        {
            cout << "-1" << endl;
            return;
        }
        else
        {
            available = false;
            passengerInfo.clear();
        }
    }

    cout << fuel << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
}