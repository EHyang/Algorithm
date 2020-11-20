#include <iostream>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;

    cin >> str;

    int a[26];

    for(int i = 0; i<26; i++)
    {
        a[i] = -1;
    }

    char idx = 'a';

    while(idx<='z')
    {
        for(int i = 0; i<str.size(); i++)
        {
            if(str[i] == idx)
            {
                a[idx-'a'] = i;
                break;
            }
        }

        idx++;
    }

    for(int i = 0; i<26; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}