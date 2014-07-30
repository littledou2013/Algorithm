#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define N 1002

struct Node
{
	int id;
	int level;
	vector<int> vec;
};
vector<Node> node;
vector<int> query;
bool has_reverse[N];
queue<int> que;
int followers(int no, int n, int l)
{
	for (int i = 1; i <= n; ++i)
		has_reverse[i] = false;
	while(!que.empty())
		que.pop();
	que.push(no);
	has_reverse[no] = true;
	node[no].level = 0;
	int count = 0;
	while(!que.empty())
	{
		no = que.front();
		que.pop();
		if (node[no].level < l)
		{
			for(int i = 0; i < node[no].vec.size(); i++)
			{
			
				if (has_reverse[node[no].vec[i]] == false)
				{
					++count;
					que.push(node[no].vec[i]);
					has_reverse[node[no].vec[i]] = true;
					node[node[no].vec[i]].level = node[no].level + 1;
				}
			}
		}
	}
	return count;
}
int main(void)
{
	int n, l;
	scanf("%d%d", &n, &l);
	node.resize(n+1);
	for (int i = 1; i <= n; i++)
	{
		node[i].id = i;
		node[i].vec.clear();
	}
	int count;
	int index;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &count);
		for (int j = 0; j < count; j++)
		{
			scanf("%d", &index);
			node[index].vec.push_back(i);
		}
	}
	int k;
	scanf("%d", &k);
	query.resize(k);
	for (int i = 0; i < k; ++i)
		scanf("%d", &query[i]);
	for (int i = 0; i < k; ++i)
	{
		printf("%d\n", followers(query[i], n, l));
	}
	return 0;
}


