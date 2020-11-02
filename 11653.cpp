#include <cstdio>
#include<vector>
#define ll long long
using namespace std;
int cnt[10001000];
ll N;
vector<ll> v;
int main()
{
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		while (N != 1) {
			if (N%i == 0) {
				N /= i; printf("%d\n", i);
			}
			else break;
		}
	}
	return 0;
	/*
	for (ll i = 2; i<= N; i++) {
		if (!cnt[i]) v.emplace_back(i);
		for (ll j = i*i; j <= N; j += i) {
			cnt[j]++;
		}
	}
	int length = v.size();
	for (int i = 0; i < length; i++) {
		ll sosu = v[i];
		if (N%sosu !=0) continue;
		while (N != 1) {
			if (N%sosu == 0) {
				N /= sosu; printf("%lld\n", sosu);
			}
			else break;
		}
		if (N == 1) break;
	}*/
	return 0;
}