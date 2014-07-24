
//对于100000000，测出来应该是yi Yi，但PAT里未给出这样的测试用例，注意自己写时需考虑从万位到千万位都为零的情况。
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char num[10][5] = {
	"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
	};

char thr[4][5] = {
	"","Shi","Bai","Qian"
	};
char per[3][4] = {"", "Wan", "Yi"};
char str[11];

int main(void)
{
	while(scanf("%s",str) != EOF)
	{
		int index = 0;
		int length = strlen(str);
		if (str[index] == '-')
		{
			printf("Fu");
			++index;
		}
		int index_next = index;
		//考虑0000类似情况
		while (index_next < length && str[index_next] == '0')
				++index_next;
		if (index_next == length)
		{
			if (index == 0)
				printf("ling");
			else 
				printf(" ling");
		}
		else
		{
			if (index == 0)
				printf("%s", num[str[index_next] - '0']);	
			else
				printf(" %s", num[str[index_next] - '0']);

			if ((length - 1 - index_next) % 4)
			{
				printf(" %s", thr[(length - 1 - index_next) % 4]);
			}
			//如果index_next不是最后一位
			else if (index_next != length - 1)
			{
				printf(" %s", per[(length - 1 - index_next) / 4]);
			}

		}
		index = index_next + 1;
		index_next = length - 1 - (length - 1 - index) / 4 * 4;
		//四个数字一组的进行处理，主要是排除100000000，一亿
		while(index < length)
		{
			int all_ling = true;
			int last_ling = false;
			int i = index;
			for(; i < index_next; ++i)
			{
				if (str[i] != '0')
				{
					if (last_ling)
					{
						printf(" ling");
						last_ling = false;
					}
					printf(" %s", num[str[i] - '0']);
					printf(" %s", thr[(length - 1 - i) % 4]);
					all_ling = false;
				}
				else
				{
					last_ling = true;
				}
			}
			if (str[i] != '0')
			{
				if (last_ling)
				{
					printf(" ling");
					last_ling = false;
				}
				printf(" %s", num[str[i] - '0']);
				if (i != length - 1)
					printf(" %s", per[(length - 1 - i) / 4]);
				all_ling = false;
			}
			else if(all_ling == false && i != length - 1)
			{
				printf(" %s", per[(length - 1 - i) / 4]);
			}
			index = index_next + 1;
			index_next = length - 1 - (length - 1 - index) / 4 * 4;
		}
	}
	return 0;
}
