#include <iostream>



#include <string>

using namespace std;

int my_pow(int a)
{
	return a * a;
}
int my_tri(int a)
{
	return a * a * a;
}

int make_num(string str)
{
	int num = 0;
	if (str.size() == 2)
	{
		num = 10;
	}
	else
	{
		num += (str[0] - 48);
	}

	return num;
}

int solution(string dartResult) {
	int answer = 0;

	int arr[4] = { 0,0,0,0 };
	int idx = 1, n_tmp;
	string tmp;

	for (int i = 0; i < dartResult.size(); i++)
	{
		if ('0' <= dartResult[i] && dartResult[i] <= '9')
		{
			tmp += dartResult[i];
			continue;
		}
		else if(dartResult[i] != '*' && dartResult[i] != '#')
		{
			n_tmp = make_num(tmp);
			tmp = "";

			switch (dartResult[i])
			{
			case 'S':
				arr[idx] += n_tmp;
				idx++;
				break;
			case 'D':
				arr[idx] += my_pow(n_tmp);
				idx++;
				break;
			case 'T':
				arr[idx] += my_tri(n_tmp);
				idx++;
				break;
			default:
				break;
			}
		}
		else
		{
			int before, present;

			before = idx - 2;
			present = idx - 1;

			switch (dartResult[i])
			{
			case '*':
				arr[present] = arr[present] * 2;
				arr[before] = arr[before] * 2;
				break;
			case '#':
				arr[present] = arr[present] * (-1);
				break;
			default:
				break;
			}
		}
	}

	for (int i = 1; i < 4; i++)
	{
		answer += arr[i];
	}

	return answer;
}

int main()
{
	string str1, str2, str6;
	str1 = "1S2D*3T";
	str2 = "1D2S#10S";
	str6 = "1T2D3D#";
	solution(str2);

}