#include <cstdio>
#include <algorithm>
#include <limits.h>
typedef long long ll;
using namespace std;
ll N, K;
int main()
{
	scanf("%lld%lld", &N, &K);
	int a;
	ll ans = LLONG_MIN;
	ll mn, mx;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a); 
		ll t1 = a - K * (i + 1);
		ll t2 = a + K * (i + 1);
		
		if (i == 0) {
			mn = t1; mx = t2;
		} else {
			ans = max(t1 - mn, ans);
			ans = max(mx - t2, ans);
			mn = min(mn, t1);
			mx = max(mx, t2);
		}
	}
	printf("%lld", ans);
	return 0;
}
