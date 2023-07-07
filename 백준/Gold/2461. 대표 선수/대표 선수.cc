#include <bits/stdc++.h>
#define DEBUG 0
#define pii pair<int, int>
using namespace std;
int N, M, ans = 2e9, mx = 0;
vector<int> v[1010];
vector<int> v_cur;
vector< vector<int>::iterator > v_nxt;

// pq : pick the minimal value from N class values
priority_queue< pair<int ,pii>, vector<pair<int,pii>>, greater<> > pq;
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
		sort(v[i].begin(), v[i].end());
		pq.push({ v[i][0], {i,0} });
		mx = max(mx, v[i][0]);
	}
    // mx : stores current maximum value
	while (!pq.empty()) {
		int nxtClass = pq.top().second.first;
		int val = pq.top().first;
		int idx = pq.top().second.second;
		pq.pop();
        
		ans = min(ans, mx - val);
        // no need to search if idx + 1 == M
        // bc we already searched when minimum is val, maximum is ans
        // even if we search for idx + 1, it always ensures 
        // mx - val < mx(idx + 1) - val
		if (idx + 1 == M) break;
		mx = max(mx, v[nxtClass][idx + 1]);
		pq.push({ v[nxtClass][idx + 1] , {nxtClass, idx + 1} });	
	}
	cout << ans;
	return 0;
}