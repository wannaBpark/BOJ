#include <stdio.h>
#include <limits.h>
#define ll long long
int N, K;
int main()
{
	scanf("%d%d", &N, &K);
	int a;
	ll ans = LLONG_MIN;
	ll mn = 1e18, mx = -1e18;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a);
		ll t1 = a - K * (i + 1);
		ll t2 = a + K * (i + 1);

		ans = t1 - mn > ans ? t1 - mn : ans;
		ans = mx - t2 > ans ? mx - t2 : ans;
		mn = mn < t1 ? mn : t1;
		mx = mx > t2 ? mx : t2;
	}
	printf("%lld", ans);
	return 0;
}