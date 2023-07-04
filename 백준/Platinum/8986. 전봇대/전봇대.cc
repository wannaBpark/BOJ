#include <bits/stdc++.h>
#define MAX_XN 1e9
#define MAX_DIST 1e16
typedef long long ll;
using namespace std;
vector<ll> v;
ll ans = MAX_XN;
ll sum = 0, N, NSumSquare;

static inline ll Dist(ll n)
{
	ll ret = 0;
	for (int i = 0; i < N; ++i) {
		ret += abs(i * n - v[i]);
	}
	return ret;
}
int main()
{
	scanf("%lld", &N);
	ll a;
	for (ll i = 0; i < N; ++i) {
		scanf("%lld", &a); 
		v.push_back(a);
		sum += a;
	}

	ll l = 1, r = MAX_XN;
	while (r - l >= 3) {
		ll mid1 = (l * 2 + r) / 3;
		ll mid2 = (l + 2 * r) / 3;
		if (Dist(mid1) > Dist(mid2)) {
			l = mid1;
		} else {
			r = mid2;
		}
	}
	ll minDist = MAX_DIST, ans = MAX_XN;
	ll curDist;
	for (ll i = l; i <= r; ++i) {
		curDist = Dist(i);
		if (minDist > curDist) {
			minDist = curDist;
			ans = i;
		}
	}
	printf("%lld", minDist);
	return 0;
}