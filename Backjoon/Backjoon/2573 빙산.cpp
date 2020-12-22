#include <iostream>

using namespace std;

int iceberg[301][301];
int tmp[301][301];
int visit[301][301];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int N, M;

void debug()
{
    cout << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << iceberg[i][j] << " ";
        }
        cout << endl;
    }
}

void reset()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            visit[i][j] = 0;
        }
    }
}

bool check(int x, int y)
{
    return (x >= 1 && x <= N && y >= 1 && y <= M);
}

void reduce()
{
    int cnt = 0;

    for (int i = 2; i < N; i++)
    {
        for (int j = 2; j < M; j++)
        {
            cnt = 0;
            if (iceberg[i][j] != 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (check(nx, ny) && iceberg[nx][ny] == 0)
                    {
                        cnt++;
                    }
                }

                if (iceberg[i][j] - cnt <= 0)
                {
                    tmp[i][j] = 0;
                }
                else
                {
                    iceberg[i][j] -= cnt;
                }
            }
        }
    }
}

void clear_ice()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (tmp[i][j] == 0 && iceberg[i][j] != 0)
            {
                iceberg[i][j] = 0;
            }
        }
    }
}

void dfs(int x, int y)
{
    visit[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (check(nx, ny) && iceberg[nx][ny] != 0)
        {
            if (visit[nx][ny] == 0)
                dfs(nx, ny);
        }
    }
}

int count_land()
{
    int l = 0;
    reset();
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (visit[i][j] == 0 && iceberg[i][j] != 0)
            {
                dfs(i, j);
                l++;
            }
        }
    }

    return l;
}

void init()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> iceberg[i][j];
            if (iceberg[i][j] != 0)
                tmp[i][j] = 1;
        }
    }
}

void solve()
{
    int land;
    int answer = 0;

    while (1)
    {
        answer++;
        reduce();
        clear_ice();
        land = count_land();
        if (land != 1)
            break;
    }
    if(land == 0)
        answer = 0;
    cout << answer;
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