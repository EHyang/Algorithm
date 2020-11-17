#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, L, R;

queue<pair<int, int>> q;      // 합칠수 있는 애들
queue<pair<int, int>> nation; // 합칠 도시들

int map[51][51];
int visit[51][51];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int answer = 0;

void init()
{
    cin >> N >> L >> R;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
            visit[i][j] = 0;
        }
    }
}

void clear_visit()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            visit[i][j] = 0;
        }
    }
}

bool check(int x, int y)
{
    return (1 <= x && x <= N && 1 <= y && y <= N);
}
bool sub(int x, int y)
{
    int gap = abs(x - y);

    return (L <= gap && gap <= R);
}

void divide(int total)
{
    while (!nation.empty())
    {
        map[nation.front().first][nation.front().second] = total;
        nation.pop();
    }
}

void solve()
{
    while (1)
    {
        int available = 0;
        clear_visit();
        int sum; // 인구 총합
        int cnt; // 연합 도시 개수
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                sum = 0;
                cnt = 0;
                if (visit[i][j] == 1)
                    continue;
                q.push(make_pair(i, j));
                nation.push(make_pair(i, j));
                visit[i][j] = 1;
                sum += map[i][j];
                cnt++;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (check(nx, ny) && visit[nx][ny] == 0)
                        {
                            if (!sub(map[x][y], map[nx][ny]))
                                continue;
                            visit[nx][ny] = 1;
                            q.push(make_pair(nx, ny));
                            nation.push(make_pair(nx, ny));
                            sum += map[nx][ny];
                            cnt++;
                            available++;
                        }
                    }
                } // 연합 찾고, 인구 합치고, 연합 도시 갯수파악

                sum /= cnt;
                divide(sum);
            }
        }
        if (available == 0)
            break;
        answer++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();

    cout << answer;

    return 0;
}