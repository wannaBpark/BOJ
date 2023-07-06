#include <bits/stdc++.h>
using namespace std;
int N,T;
vector<int> v;
bool affordable(int sz)
{
	bool ret = true;
	priority_queue<pair<int, int>, vector<pair<int,int>> , greater<pair<int,int> > > pq;
	int start = max(1, v[0] - T + 1); 
	int end = start + T - 1;
	pq.push(make_pair(start, end));
	for (int i = 1; i < N; ++i) {
		int& cur = v[i];
		start = max(1, cur - T + 1);
		if (pq.size() >= sz) {
			int mn = pq.top().second + 1;
			start = max(start, mn);
			if (mn > cur) {
				return ret = false;
			}
			pq.pop();
        }
		end = start + T - 1;
		pq.push(make_pair(start, end));
	}
	return ret;
}
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N >> T;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	int ans = 2e9;
	int l = 1, r = 1e9;

	while (l <= r) {
		int mid = (l + r) / 2;
		bool res = affordable(mid);
		if (res == true) {
			r = mid - 1;
			ans = min(mid, ans);
		} else {
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}