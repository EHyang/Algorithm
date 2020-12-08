#include <iostream>
#include <string>

using namespace std;

string str;
int cnt = 0;

void init()
{
    cin >> str;
}

void solve()
{
    for(int i = 0; i<str.length(); i++)
    {
        char s = str[i];

        if (s == 'n' || s == 'l')
        {
            if (str[i + 1] == 'j') 
            {
                continue;
            }
        }
        else if (s == 'c' || s == 's' || s == 'z')
        {
            if (str[i + 1] == '=' || str[i + 1] == '-')
            {
                continue;
            }
        }
        else if (s == 'd') {
            if (str[i + 1] == '-')
            {
                continue;
            }
            if (str[i + 1] == 'z' && str[i + 2] == '=')
            {
                continue;
            }
        }

        cnt++;
    }

    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    solve();

    return 0;
}