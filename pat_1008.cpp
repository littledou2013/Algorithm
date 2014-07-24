#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int last = 0;
		int now;
		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &now);
			if (now > last)
			{
				result += (now - last) * 6;
			}
			else 
				result += (last - now) * 4;
			result += 5;
			last = now;
		}
		printf("%d\n", result);
	}
	return 0;
}
