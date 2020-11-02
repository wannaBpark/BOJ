#include <cstdio>
#define min(a,b) a>b ? b:a
int main()
{
	int burger = 2000,drink = 2000,a;
	for (int i = 0; i < 3; i++) scanf("%d", &a), burger = min(burger, a);
	for (int i = 0; i < 2; i++) scanf("%d", &a), drink = min(drink, a);
	printf("%d\n", burger + drink - 50);
	return 0;

}