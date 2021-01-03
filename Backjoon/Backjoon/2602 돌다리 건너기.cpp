#include <iostream>
#include <string>
using namespace std;

string bridge[2];
string road;

int dp[21][101][2];

void init()
{
    cin >> road;

    for (int i = 0; i < 2; i++)
    {
        cin >> bridge[i];
    }
}

void solve()
{
    int road_length = road.length();
    int bridge_length = bridge[0].length();

    for (int j = 0; j <= bridge_length; j++)
    {
        dp[0][j][0] = 1;
        dp[0][j][1] = 1;
    }

    for (int i = 1; i <= road_length; i++)
    {
        for (int j = 1; j <= bridge_length; j++)
        {
            if (road[i - 1] == bridge[0][j - 1])
                dp[i][j][0] += dp[i - 1][j - 1][1];
            if (road[i - 1] == bridge[1][j - 1])
                dp[i][j][1] += dp[i - 1][j - 1][0];
            dp[i][j][0] += dp[i][j - 1][0];
            dp[i][j][1] += dp[i][j - 1][1];
        }
    }

    cout << dp[road_length][bridge_length][0] + dp[road_length][bridge_length][1]; 
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