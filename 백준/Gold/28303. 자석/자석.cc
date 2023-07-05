#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <limits.h>
typedef long long ll;
using namespace std;
ll N, K;
vector<ll> v;
vector<ll> v1;
vector<ll> v2;
int main()
{
	scanf("%lld%lld", &N, &K);
	int a;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a); v.push_back(a);
		v1.push_back(a - K * (i + 1));
		v2.push_back(a + K * (i + 1));
	}

	ll ans = LLONG_MIN;
	ll mn = v1[0];
	for (int i = 1; i < N; ++i) {
		ans = max(v1[i] - mn, ans);
		mn = min(mn, v1[i]);
	}
	mn = v2[N - 1];
	for (int i = N - 2; i >= 0; --i) {
		ans = max(v2[i] - mn, ans);
		mn = min(mn, v2[i]);
	}
	printf("%lld", ans);
	return 0;
}
