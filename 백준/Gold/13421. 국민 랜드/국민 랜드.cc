#include <bits/stdc++.h>
#define X 0
#define Y 1
#define MAXN 4
typedef long long ll;
using namespace std;
vector<pair<ll, ll>> v;
ll quaters[MAXN][2] = { {-1,-1}, {-1,1}, {1,-1}, {1,1 }};

int main()
{
	ll x, y;
	bool nonZero = false;
	for (int i = 0; i < MAXN; ++i) {
		scanf("%lld %lld", &x, &y);
		v.push_back({ x,y });
		if (x != 0 || y != 0) nonZero = true;
	}
	if (nonZero == false) {
		puts("1");
		return 0;
	}

	vector<int> permutation = { 0,1,2,3 };
	ll min_Dist = 1e14;
	ll ans = 0;
	do {
		vector<pair<ll, ll>> v_permute;
		vector<ll> v_sort;
		for (int i = 0; i < MAXN; ++i) {
			int idx = permutation[i];
			x = v[idx].first * quaters[i][X];
			y = v[idx].second * quaters[i][Y];
			v_sort.push_back(x); v_sort.push_back(y);
		}
		sort(v_sort.begin(), v_sort.end());

		ll cur_ans = v_sort[4];
		ll cur_Dist = 0;
		for (auto val : v_sort) {
			cur_Dist += 1ll*abs(cur_ans - val);
		}

		if (cur_Dist < min_Dist) {
			min_Dist = cur_Dist;
			ans = cur_ans;
		} else if (cur_Dist == min_Dist) {
			ans = max(ans, cur_ans);
		}
	} while (next_permutation(permutation.begin(), permutation.end()));

	printf("%lld", ans*2ll);
	return 0;
}
