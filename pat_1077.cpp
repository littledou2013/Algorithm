#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str1[270];
char str2[270];
//求共同后缀
void commonSuffix(char *str1, char *str2)
{
	int length1 = strlen(str1);
	int length2 = strlen(str2);
	int i = length1 - 1;
	int j = length2 - 1;
	while(i >= 0 && j >= 0 && str1[i] == str2[j])
	{
		--i;
		--j;
	}
	++j;
	i = 0; 
	while(j < length2)
	{
		str1[i] = str2[j];
		++i;
		++j;
	}
	str1[i] = '\0';

}
int main(void)
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
	getchar();
	gets(str1);
	for (int i = 1; i < n; i++)
	{
		gets(str2);
		if (strlen(str1))
		{
			commonSuffix(str1,str2);
		}
		else
			continue;
	}
	if(strlen(str1))
		printf("%s\n",str1);
	else
		printf("nai\n");
	}
	return 0;
}
