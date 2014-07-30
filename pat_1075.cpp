#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct User
{
	int id;
	int solve;
	int all;
	bool sub;
	bool su[5];
	int score[5];
	User(): solve(0), all(0), sub(false)
	{
		memset(score, 0, sizeof(score));
		memset(su, false, sizeof(su));
	}
	bool operator < (const User & user) const
	{
		if (all != user.all)
			return all > user.all;
		if (solve != user.solve)
			return solve > user.solve;
		if (sub != user.sub)
			return sub;
		return id < user.id;
	}
};

int string2int(char *str)
{
	int length = strlen(str);
	int result = 0;
	for (int i = 0; i < length; --i)
	{
		result = result * 10 + (str[i] - '0');
	}
	return result;
}
User user[10002];
int pro_score[5];

int main(void)
{
	int N, K, M;
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 1; i <= N; ++i)
	{
		user[i].id = i;
	}
	for (int i = 0; i < K; ++i)
		scanf("%d", &pro_score[i]);
	int user_index;
	int pro_num;
	int get_score;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &user_index);
		scanf("%d%d", &pro_num, &get_score);
		if (get_score != -1)
			user[user_index].sub = true;
		if (user[user_index].score[pro_num - 1] < get_score)
		{
			user[user_index].score[pro_num - 1] = get_score;
			if (get_score == pro_score[pro_num - 1])
				++(user[user_index].solve);
		}
		user[user_index].su[pro_num - 1] = true;
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < K; ++j)
			user[i].all += user[i].score[j];
	}
	sort(user+1, user+N+1);
	int last_index = 1;
	int i = 1;
	while (i <= N && user[i].sub)
	{
		if (user[i].all != user[last_index].all)
		{
			last_index = i;
			
		}
		printf("%d %05d %d", last_index, user[i].id, user[i].all);
		for (int j = 0; j < K; ++j)
		{
			if (user[i].su[j])
				printf(" %d", user[i].score[j]);
			else
				printf(" -");
		}
		printf("\n");
		++i;
	}
	if (i == 1)
	{
		printf("%d %05d %d", i, user[i].id, user[i].all);
		for (int j = 0; j < K; ++j)
		{
			if (user[i].su[j])
				printf(" %d", user[i].score[j]);
			else
				printf(" -");
		}
		printf("\n");
	}
	return 0;
}
