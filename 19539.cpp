#include <cstdio>
int cnt1 = 0, cnt2=0, N, a,total = 0;
int ans = true;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		total += a;
		cnt2 += (a/2);
	}
	if (total % 3 != 0) ans = false;
	else if ( (total/3) > cnt2) ans = false;
	ans == 1 ? puts("YES") : puts("NO");
	return 0;
}
