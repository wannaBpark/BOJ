#include <iostream>
#include <vector>
#include<utility>
#include <algorithm>
using namespace std;
int N,ans;
vector<pair<int,int>> v[10001];
vector<int> mCost[10001];

int dc(int par, int cost)
{
	//printf("%d %d\n", par, cost);
	//if (v[par].empty()) { printf("현재 자식없는 색히들: %d %d\n", par,cost); return cost; }
	//if (v[par].size() == 1 && v[v[par][0].first].empty()) return cost+v[par][0].second;
	for (int i = 0; i < v[par].size(); i++) {
		int child = v[par][i].first, val = v[par][i].second;
		//printf("%d %d\n", child, val);
		int mx = val;
		if (!v[child].empty()) { //자식이 없는 노드는 탐색조차 안한다
			mx += dc(child, cost+val);
		}
		mCost[par].push_back(mx);
	}
	if (mCost[par].size() == 1) {
		ans = max(cost + mCost[par][0], ans);
		//자식이 하나일때, 경우의 수 2)만이 해당한다.
		return mCost[par][0];	//자식을 하나 갖고있는 노드.
		//어차피 자식이 없는 노드는 탐색조차 안한다.(!v[chlid].empty())
	}
	sort(mCost[par].begin(), mCost[par].end());
	int length = mCost[par].size();
	int tmp = max(mCost[par][length - 1], mCost[par][length - 2]);
	//printf("first %d %d\n", mCost[par][length - 1] + mCost[par][length - 2], ans);
	ans = max(mCost[par][length - 1] + mCost[par][length - 2], ans);
	// 현재 노드의 자식 두개를 합한것과 ans값 비교
	// 자식 2
	//printf("second %d %d\n", tmp + cost, ans);
	ans = max(tmp + cost, ans);
	//현재 노드의 자식 노드 중 최댓 값(tmp) + 현재 노드의 윗쪽(루트)쪽의 값(cost)
	// = 자식1+부모1
	return max(mCost[par][length - 1],mCost[par][length - 2]);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> N;
	int a,b,c;
	for (int i = 0; i < N - 1; i++) cin >> a >> b >> c, v[a].push_back({ b,c });
	//경우의수는 방향기준으로 나뉜다 : 1) 자식 두개(아래쪽) 2) 자식1, 부모1 (위1아래1)
	/*for (int i = 1; i <= N; i++) {
		if(v[i].size() >1)
	}*/
	dc(1, 0);
	cout<< ans <<endl;
	return 0;
}