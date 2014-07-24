#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Grade
{
	char name[11];
	char id[11];
	int grade;
	/*bool operator < (const Grade &a)
	{
		return grade > a.grade;
	}*/
};
bool cmp(Grade a, Grade b)
{
	return a.grade > b.grade;
}

vector<Grade> stu;

int main(void)
{
	int n;
	scanf("%d",&n);
	Grade gra;
	while (n--)
	{
		scanf("%s%s%d", gra.name, gra.id, &gra.grade);
		stu.push_back(gra);
	}
	sort(stu.begin(),stu.end(),cmp);
	int N1, N2;
	scanf("%d%d",&N1,&N2);
	bool has_record = false;
	for	(int i = 0; i < stu.size(); ++i)
	{
		if	(stu[i].grade <= N2 && stu[i].grade >= N1)
		{
			has_record = true;
			printf("%s %s\n",stu[i].name,stu[i].id);
		}
	}
	if(!has_record)
		printf("NONE\n");
	return 0;
}
