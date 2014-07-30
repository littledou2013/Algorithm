#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

#define SIZE 100000
struct Mem
{
	int level;
	int weight;
	vector<int> next;
	Mem():level(0), weight(0) 
	{
		next.clear();
	}
};

Mem vec[100004];
queue<int> que;

int main(void)
{
	while(true)
	{
	int N;
	double P, r;
	scanf("%d %lf %lf", &N, &P, &r);
	for (int i = 0; i < N; ++i)
	{
		int k;
		scanf("%d", &k);
		if (k != 0)
		{
			for	(int j = 0; j < k; ++j)
			{
				int num;
				scanf("%d", &num);
				vec[i].next.push_back(num);
			}
		}
		else
		{
			scanf("%d", &vec[i].weight);
		}
	}
	int index = 0;
	que.push(index);
	double result = 0;
	while(!que.empty())
	{
		index = que.front();
		que.pop();
		for (int i = 0; i < vec[index].next.size(); ++i)
		{
			que.push(vec[index].next[i]);
			vec[vec[index].next[i]].level = vec[index].level + 1;
		}
		if (vec[index].weight)
		{
			result += pow(1 + r/100, vec[index].level) * P * vec[index].weight;
		}
	}
	printf("%.1lf\n", result);
}
	return 0;
}
