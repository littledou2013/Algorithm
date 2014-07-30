#include<cstdio>
#include<cstring>
using namespace std;

int gcd(int a, int b)
{
	int temp;
	while (a % b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return b;
}
void simple_ration(int &a, int &b)
{
	int gc = gcd(a, b);
	a /= gc;
	b /= gc;
}

void two_ration(int &a, int &b, int c, int d)
{
	if (c == 0)
		return;
	int gc = gcd(b, d);

	a *= d / gc;
	c *= b / gc;
	b = b * d / gc;
	a += c;
	simple_ration(a, b);
}
int main(void)
{
	int n;
	int a, b;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d/%d", &a, &b);
		int c, d;
		for (int i = 1; i < n; ++i)
		{
			scanf("%d/%d", &c, &d);
			two_ration(a, b, c, d);
		}
		bool has_space = false;
		if (a == 0)
			printf("0");
		else
		{
			if (a / b)
			{
				printf("%d", a/b);
				a %= b;
				if (a)
					printf(" %d/%d", a, b);	
			}
			else
				printf("%d/%d", a, b);
		}
		printf("\n");
	}
	return 0;
}
