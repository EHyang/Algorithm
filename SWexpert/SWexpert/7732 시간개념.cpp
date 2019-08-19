#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

int make_int(char a, char b)
{
	return (a - '0') * 10 + (b - '0');
}
string make_result(int hour, int min, int sec)
{
	string answer;
	if (hour < 10)
	{
		answer += '0';
		answer += (hour + '0');
	}
	else answer += to_string(hour);

	answer += ':';
	if (min < 10)
	{
		answer += '0';
		answer += (min + '0');
	}
	else answer += to_string(min);
	answer += ':';
	if (sec < 10)
	{
		answer += '0';
		answer += (sec + '0');
	}
	else answer += to_string(sec);

	return answer;
}
int main()
{
	char now[8], meet[8];
	int T, count;


	cin >> T;
	count = 1;
	while (T--)
	{
		int hour_now, hour_met, hour=0;
		int min_now, min_met, min=0;
		int sec_now, sec_met,sec=0;

		for (int i = 0; i < 8; i++)
		{
			cin >> now[i];
		}
		for (int i = 0; i < 8; i++)
		{
			cin >> meet[i];
		}

		hour_now = make_int(now[0], now[1]);
		min_now = make_int(now[3], now[4]);
		sec_now = make_int(now[6], now[7]);

		hour_met = make_int(meet[0], meet[1]);
		min_met = make_int(meet[3], meet[4]);
		sec_met = make_int(meet[6], meet[7]);

		if (sec_met - sec_now < 0)
		{
			sec += (sec_met - sec_now + 60);
			min -= 1;
		}
		else
		{
			sec += (sec_met - sec_now);
		}
		if (sec >= 60)
		{
			sec = 0;
			min += 1;
		}

		if (min_met - min_now + min < 0)
		{
			min += (min_met - min_now + 60);
			hour -= 1;
		}
		else
		{
			min += (min_met - min_now);
		}
		if (min >= 60)
		{
			min = 0;
			hour += 1;
		}

		if (hour_met - hour_now + hour < 0)
		{
			hour += (hour_met - hour_now + 24);
		}
		else
			hour += (hour_met - hour_now);

		cout << "#" <<count++ << " " << make_result(hour,min,sec) << endl;
	}
	return 0;
}