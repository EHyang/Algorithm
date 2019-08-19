//#include <iostream>
//#include <map>
//#define endl '\n'
//using namespace std;
//
//int Answer;
//map<int, int> memo;
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//	int T, test_case;
//	int x, A, B, jump, count;
//
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		Answer = 0;
//		cin >> A >> B;
//		for (int i = A; i <= B; i++)
//		{
//			if (memo.find(i) != memo.end())
//			{
//				if (memo[i] > Answer) Answer = memo[i];
//				continue;
//			}
//			count = 0;
//			x = 0;
//			jump = 1;
//			while (x != i)
//			{
//				if (x + jump <= i)
//				{
//					x += jump;
//					jump++;
//					count++;
//				}
//				else
//					jump = 1;
//			}
//			memo[i] = count;
//			if (memo[i] > Answer) Answer = memo[i];
//		}
//
//		cout << "Case #" << test_case + 1 << endl;
//		cout << Answer << endl;
//	}
//
//	return 0;
//}

/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define PI 3.14159265358979323846
using namespace std;

double Answer;
vector<int> l, r, h;
int main(int argc, char** argv)
{
	int T, test_case;
	//	ios_base::sync_with_stdio(false);
	//	cin.tie(0); cout.tie(0);

	int R, S, E;//R 반지름, S 출발점, E 도착점
	int H; // 내가만듬 높이
	int N;
	int t1, t2, t3, ja;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> R >> S >> E >> N;
		H = R;
		ja = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> t1 >> t2 >> t3;
			l.push_back(t1);
			r.push_back(t2);
			h.push_back(t3);
		}
		while (ja != N)
		{
			Answer += (l[ja] - R) - S;
			Answer += r[ja] - l[ja];
			if (h[ja] >= R)
			{
				Answer += (h[ja] - R) * 2;
				Answer += PI * R;
			}
			else
			{
				Answer += ((atan2l(sqrt((R*R) - ((R - h[ja])*(R - h[ja]))), R - h[ja]))) * R * 2.1440288;
				
			}
			S = r[ja] + R;
			ja++;
		}
		Answer += (E - S);
		l.clear();
		r.clear();
		h.clear();


		cout << "Case #" << test_case + 1 << endl;
		printf("%.12f\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}