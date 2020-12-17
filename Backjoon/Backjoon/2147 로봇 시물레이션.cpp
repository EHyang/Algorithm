#include <iostream>
#include <vector>

using namespace std;

vector<pair<pair<int, int>, char>> v;

int land[101][101];

int N, M, A, B;
int x, y;
char ch;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool ground(int x, int y)
{
    return (x >= 1 && x <= A && y >= 1 && y <= B);
}

int dir(char a)
{
    switch (a)
    {
    case 'N':
        return 0;
        break;
    case 'E':
        return 1;
        break;
    case 'S':
        return 2;
        break;
    case 'W':
        return 3;
        break;
    default:
        break;
    }

    return -1;
}

char dir(int a)
{
    switch (a)
    {
    case 0:
        return 'N';
        break;
    case 1:
        return 'E';
        break;
    case 2:
        return 'S';
        break;
    case 3:
        return 'W';
        break;
    default:
        break;
    }

    return 'x';
}

char rotate(int robot, char lr)
{
    int d = dir(v[robot].second);

    if (lr == 'R')
    {
        d = d + 1 > 3 ? 0 : d + 1;
    }
    else
    {
        d = d - 1 < 0 ? 3 : d - 1;
    }

    return dir(d);
}

void init()
{
    cin >> A >> B >> N >> M;

    v.push_back(make_pair(make_pair(0, 0), 'x'));
    for (int i = 1; i <= N; i++)
    {
        cin >> x >> y >> ch;
        land[x][y] = i;
        v.push_back(make_pair(make_pair(x, y), ch));
    }
}

void solve()
{
    int robot, repeat;
    char cmd;
    for (int tc = 1; tc <= M; tc++)
    {
        cin >> robot >> cmd >> repeat;

        for (int i = 0; i < repeat; i++)
        {
            int x = v[robot].first.first;
            int y = v[robot].first.second;
            int d = dir(v[robot].second);

            if (cmd == 'F')
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (!ground(nx, ny))
                {
                    cout << "Robot " << robot << " crashes into the wall";
                    return;
                }

                if (land[nx][ny] != 0)
                {
                    cout << "Robot " << robot << " crashes into robot " << land[nx][ny];
                    return;
                }

                land[nx][ny] = land[x][y];
                land[x][y] = 0;
                v[robot].first.first = nx;
                v[robot].first.second = ny;
                /*앞으로 전진*/
            }
            else if (cmd == 'L' || cmd == 'R')
            {
                v[robot].second = rotate(robot, cmd);
            }
        }
    }

    cout << "OK";
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