/*#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define SCHSIZE 100
#define STUSIZE 40000
#define MAXCHOICES 5

struct Stu
{
	int id;
	int ge;
	int gi;
	int choices[MAXCHOICES];
	bool operator < (const Stu & stu) const
	{
		if ((ge + gi) != (stu.ge + stu.gi))
			return (ge + gi) > (stu.ge + stu.gi);
		return ge > stu.ge;

	}
};

int sch[SCHSIZE];
Stu stu[STUSIZE];
struct STU_ID
{
	int num;
	int id;
	bool operator < (const STU_ID &stu) const
	{
		return id < stu.id;
	}
};
vector<STU_ID> vec[SCHSIZE];

int main()
{	while(true)
	{int N, M, K;
	//N个学生，M个学校，K个选择
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &sch[i]);
		vec[i].clear();
	}
	for (int i = 0; i < N; ++i)
	{
		stu[i].id = i;
		scanf("%d%d", &stu[i].ge, &stu[i].gi);
		for (int j = 0; j < K; ++j)
		{
			scanf("%d", &stu[i].choices[j]);
		}
	}
	sort(stu,stu+N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			int choice = stu[i].choices[j];
			if (sch[choice] > 0 || (!vec[choice].empty() && (stu[vec[choice].back().num].ge) == stu[i].ge && stu[vec[choice].back().num].gi == stu[i].gi))
			{
				sch[choice] -= 1;
				STU_ID stu_id; 
				stu_id.num = i;
				stu_id.id = stu[i].id;
				vec[choice].push_back(stu_id);

				break;
			}
		}
	}
	for(int i = 0; i < M; ++i)
	{
		sort(vec[i].begin(),vec[i].end());
		if (vec[i].size() >= 1)
			printf("%d",stu[vec[i][0].num].id);
		for(int j = 1; j < vec[i].size(); ++j)
			printf(" %d", stu[vec[i][j].num].id);
		printf("\n");
	}
	}
	return 0;
}*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define SCHSIZE 100
#define STUSIZE 40000
#define MAXCHOICES 5

struct Stu
{
	int id;
	int ge;
	int gi;
	int choices[MAXCHOICES];
	bool operator < (const Stu & stu) const
	{
		if ((ge + gi) != (stu.ge + stu.gi))
			return (ge + gi) > (stu.ge + stu.gi);
		return ge > stu.ge;

	}
};

int sch[SCHSIZE];
Stu stu[STUSIZE];
vector<int> vec[SCHSIZE];

int main()
{	while(true)
	{int N, M, K;
	//N个学生，M个学校，K个选择
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &sch[i]);
		vec[i].clear();
	}
	for (int i = 0; i < N; ++i)
	{
		stu[i].id = i;
		scanf("%d%d", &stu[i].ge, &stu[i].gi);
		for (int j = 0; j < K; ++j)
		{
			scanf("%d", &stu[i].choices[j]);
		}
	}
	sort(stu,stu+N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			int choice = stu[i].choices[j];
			if (sch[choice] > 0 || (!vec[choice].empty() && (stu[vec[choice].back()].ge) == stu[i].ge && stu[vec[choice].back()].gi == stu[i].gi))
			{
				sch[choice] -= 1;
				vec[choice].push_back(i);
				break;
			}
		}
	}
	for(int i = 0; i < M; ++i)
	{
		for(int j = 0; j < vec[i].size(); ++j)
		{
			vec[i][j] = stu[vec[i][j]].id;
		}
		sort(vec[i].begin(),vec[i].end());
		if (vec[i].size() >= 1)
			printf("%d",vec[i][0]);
		for(int j = 1; j < vec[i].size(); ++j)
			printf(" %d", vec[i][j]);
		printf("\n");
	}
	}
	return 0;
}
