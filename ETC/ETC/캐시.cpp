#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	list<string> lru;
	list<string>::iterator it;

	for (int i = 0; i < cities.size(); i++)
	{
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
	}
	for (int i = 0; i < cities.size(); i++)
	{
		it = find(lru.begin(), lru.end(), cities[i]);

		if (cacheSize == 0)
		{
			answer += 5;
		}
		else if (cacheSize > 0)
		{
			if (lru.empty() || lru.size() < cacheSize)
			{
				if (it != lru.end())
				{
					lru.erase(it);
					lru.push_back(cities[i]);
					answer++;
				}
				else
				{
					lru.push_back(cities[i]);
					answer += 5;
				}
			}
			else
			{
				if (it == lru.end())
				{
					lru.pop_front();
					lru.push_back(cities[i]);
					answer += 5;
				}
				else
				{
					lru.erase(it);
					lru.push_back(cities[i]);
					answer++;
				}
			}

		}
	}

	return answer;
}
int main()
{
	vector<string> str = { "Jeju","Pangyo", "Seoul","NewYork","LA","Jeju","Pangyo","Seoul","NewYork","LA" };
	vector<string> str2 = { "Jeju","Pangyo", "Seoul","Jeju","Pangyo","Seoul","Jeju","Pangyo","Seoul" };
	vector<string> a = { "a","a","c","c","a","A","d","c","f","z" };
	vector<string> b = { "a","b","c","d","e" };
	solution(0,b);
}