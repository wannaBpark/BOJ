#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,ans=1,nxt=0;
vector<pair<int, int> > v;
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++)
		cin >> a >> b, v.emplace_back(make_pair(b, a));
	sort(v.begin(), v.end());
	for (int i = 1; i < N; i++) {
		//(다음 회의 종료시간이 현재보다 크거나 같고,) 다음 시작시간이 현재 종료시간보다 크거나 같을때.
		if (/*v[nxt].first <= v[i].first &&*/ v[i].second >= v[nxt].first) ++ans,nxt=i; //이미 정렬해놓았으므로 당연하다
		cout << v[i].first << " " << v[i].second << endl;
	}
	cout << ans;
	return 0;
}