#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;
int N,T;
vector<int> v;
bool affordable(int sz) // 최대로 겹치는 세미나 수를 sz개 이하로 배정 가능?
{
	priority_queue<pair<int, int>, vector<pair<int,int>> , greater<pair<int,int> > > pq;
	int start = max(1, v[0] - T + 1); 
	int end = start + T - 1;
	pq.push(make_pair(start, end));
	for (int i = 1; i < N; ++i) {
		int& cur = v[i];
		start = max(1, cur - T + 1);
		if (pq.size() >= sz) {
			// mn : 맨 앞의 세미나의 끝나는 날짜 + 1
			// = 현재 cur인 세미나가 시작할 수 있는 가장 작은 수
			// mn이 현재 배정하려는 cur보다 크다면
			// 배정할 수 없다는 뜻 (세미나에 외부강사 초청 불가)
			int mn = pq.top().second + 1;
			start = max(start, mn);	
			if (mn > cur) {
				return false;
			}
			pq.pop();
		}
		end = start + T - 1;
		pq.push(make_pair(start, end));
	}
	return true;
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

	int ans = 1e9+1;
	int l = 1, r = 200000;

	//bool res = affordable(2);
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