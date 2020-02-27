//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//string binary(int a,int n)
//{
//	char tmp[16];
//	string str;
//	for (int i = 0; i < n; i++)
//	{
//		tmp[i] = (a % 2) + 48;
//		a /= 2;
//	}
//
//	for (int i = n-1; i >=0; i--)
//	{
//		str += tmp[i];
//	}
//
//	return str;
//}
//
//string make_map(string a, string b,int n)
//{
//	string map;
//	for (int i = 0; i < n; i++)
//	{
//		map += (a[i] | b[i]);
//	}
//
//	return map;
//}
//
//vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
//	vector<string> answer;
//
//	string str1, str2;
//	string map;
//	for (int i = 0; i < n; i++)
//	{
//		str1 += binary(arr1[i], n);
//		str2 += binary(arr2[i], n);
//
//		map += make_map(str1, str2, n);
//		str1 = "";
//		str2 = "";
//	}
//	int count = 0;
//	string tmp;
//	for (int i = 0; i < map.size(); i++)
//	{
//		if (map[i] == '1')
//			tmp += '#';
//		else
//			tmp += " ";
//		count++;
//		if (count == n)
//		{
//			answer.push_back(tmp);
//			tmp = "";
//			count = 0;
//		}
//	}
//
//	return answer;
//}
//
//int main()
//{
//	vector<int> v1, v2;
//
//	v1.push_back(9);
//	v1.push_back(20);
//	v1.push_back(28);
//	v1.push_back(18);
//	v1.push_back(11);
//
//	v2.push_back(30);
//	v2.push_back(1);
//	v2.push_back(21);
//	v2.push_back(17);
//	v2.push_back(28);
//	
//	int n;
//
//	cin >> n;
//
//	//solution(n, v1, v2);
//	int a = 9;
//	int b = 30;
//
//	int c = 9 | 30;
//
//	cout << c;
//
//	return 0;
//}
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <int> v, v1;
vector <char> res;
int n;

void bin(int x) {
	while (x > 0) {
		if (x % 2 == 1) {
			res.push_back('#');
		}
		else
			res.push_back(' ');
		x /= 2;
	}
	if (res.size() < n) {
		res.push_back(' ');
	}
	reverse(res.begin(), res.end());

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v1.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int x = v[i] | v1[i];
		bin(x);
		for (int j = 0; j < n; j++) {
			cout << res[j];
		}cout << '\n';
		res.resize(0);

	}

}