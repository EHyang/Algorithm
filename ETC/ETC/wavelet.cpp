#include <Iostream>
#include <algorithm>
#include <vector>


#define endl '\n'

using namespace std;


vector<int> v;
vector<int> t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	v.push_back(0);



	int n, tmp;

	cin >> n;


	// input
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	//solution

	int y = 1;

	while (y < n)
	{
		t = v;
		int tmp;
		int cnt = 1;
		for (int i = 1; cnt<=y; i+=2)
		{
			tmp = v[cnt];

			t[i] = (v[cnt] + v[cnt + y])/2;
			t[i + 1] = tmp - t[i];
			cnt++;
		}
		v = t;
		y *= 2;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}