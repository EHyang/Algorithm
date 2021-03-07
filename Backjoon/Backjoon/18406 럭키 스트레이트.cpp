#include <iostream>
#include <string>

using namespace std;

string input;

void init()
{
    cin >> input;
}

void solve()
{
    int half = input.size() / 2;
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < half; i++)
    {
        sum1 += (input[i] - '0');
    }
    for (int i = half; i < input.size(); i++)
    {
        sum2 += (input[i] - '0');
    }

    if (sum1 == sum2)
        cout << "LUCKY";
    else
        cout << "READY";
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