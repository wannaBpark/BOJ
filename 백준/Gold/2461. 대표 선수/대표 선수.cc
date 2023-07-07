#include <bits/stdc++.h>
#define DEBUG 0
#define pii pair<int, int>
using namespace std;
int N, M, ans = 0;
vector<int> v[1010];
vector<int> v_cur;
vector< vector<int>::iterator > v_nxt;

priority_queue<pii> pq;
int Diff()
{
	int mx = -1;
	int mn = 1e9 + 1;
	for (auto& i : v_cur) {
		mx = max(mx, i); mn = min(mn, i);
	}
	return mx - mn;
}
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int a; cin >> a;
			v[i].push_back(a);
		}
		sort(v[i].begin(), v[i].end(), greater<int>());
		v_cur.push_back(v[i][0]);
		v_nxt.push_back(v[i].begin());
		if (N > 1) pq.push({ v[i][1], i });
	}
	if (N == 1) {
		cout << Diff();
	}
	int ans = Diff();
	
	while (!pq.empty()) {
		int nxtClass = pq.top().second;
		int val = pq.top().first;
		auto& it = v_nxt[nxtClass];

		v_cur[nxtClass] = *it;
		++it;
		pq.pop();
		ans = min(ans, Diff());
		if (it != v[nxtClass].end()) {
			pq.push({ *it, nxtClass });
		}
	}
	cout << ans;
	return 0;
}