#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;

    cin >> tc;

    while(tc--){
        int cnt = 0;
        int score = 0;
        string input;

        cin >> input;

        for(int i = 0; i<input.length();i++)
        {
            if(input[i] == 'O')
            {
                cnt++;
                score+=cnt;
            }
            else
            {
                cnt=0;
            }
        }

        cout << score << endl;
    }

    return 0;
}