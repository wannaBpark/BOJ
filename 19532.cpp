#include <cstdio>
int a, b, c, d, e, f;
int x, y;
int main()
{
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	y = (a * f - d * c) / (a * e - b * d);
	x = (e * c - b * f) / (a * e - b * d);
	printf("%d %d", x, y);
	return 0;
}