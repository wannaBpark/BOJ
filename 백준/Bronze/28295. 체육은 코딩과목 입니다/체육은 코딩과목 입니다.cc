#include <cstdio>

int main()
{
	int ans = 0, a;
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &a);
		if (a == 1) ans += 1;
		else if (a == 2) ans += 2;
		else ans -= 1;
	}
	ans += 44;
	if (ans % 4 == 0) puts("N");
	else if (ans % 4 == 1) puts("E");
	else if (ans % 4 == 2) puts("S");
	else if (ans % 4 == 3) puts("W");
	return 0;
}