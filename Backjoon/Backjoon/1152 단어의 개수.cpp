#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string input,a;
    stringstream ss;
    int cnt = 0;

    getline(cin, input);

    ss.str(input);

    while(ss>>a)
    {
        cnt++;
    }

    cout << cnt;

    return 0;
}