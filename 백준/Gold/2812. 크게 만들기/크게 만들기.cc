#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v;
vector<bool> v_print;
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	string s;
	cin >> N >> M;
	cin >> s;
	int mx = s[0];
	v.push_back(s[0]);
	int i;
	for (i = 1; i < N && M > 0; ++i) {
		int nxt = s[i];
		while (!v.empty() && M > 0 && nxt > v[v.size() - 1]) {
			v.pop_back();
			--M;
		}
		v.push_back(nxt);
	}
	for (; i < N; ++i) {
		v.push_back(s[i]);
	}
	while (M--) {
		v.pop_back();
	}
	for (auto& n : v) {
		cout << (char)n;
	}
	return 0;
}