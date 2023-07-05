#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <functional>
#define DEBUG 0
//#define sz(a) a.size()
typedef long long ll;
using namespace std;
int N, K, M;
vector<tuple<ll, int, int>> edge;
vector<map<int,ll>> v;
ll ans[50010] = { 0, };
int p[100010];
int sz[100010];
int find(int a)
{
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
void merge(ll w, int a, int b)
{
	// Merge Given Two WareHouses (a, b)
	int p1 = find(a), p2 = find(b);
	// Same parents, already connected components
	if (p1 == p2) return;
	
	if (sz[p1] > sz[p2]) swap(p1, p2);

	a = p1, b = p2;
	auto& m_elements = v[a];
	for (auto& m : m_elements) {
		auto company = m.first;
		auto cnt1 = m.second;
		auto cnt2 = v[b][company];

		ans[company] += cnt1 * cnt2 * w;
		
		v[b][company] += cnt1;
#if DEBUG == true
		printf("p1 p2 %d %d\ncompany cnt1 cnt2 %d %lld %lld\n", p1, p2, company, cnt1, cnt2);
#endif
	}
	m_elements.clear();
	p[a] = b;
	sz[b] += sz[a];

}
int main()
{
	//printf("%d", __cplusplus);
#if DEBUG == true
	freopen("input.txt", "r", stdin);
#endif
	
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 1; i <= N+1; ++i) {
		map<int, ll> m; 
		v.push_back(m);
	}
	for (int i = 1; i <= N; ++i) {
		int company;
		scanf("%d", &company);
		auto& m = v[i];
		m[company] = 1; // 각 창고가 가지고 있는 회사와 그 개수 저장
		p[i] = i; sz[i] = 1; // 각 창고의 부모, 창고가 연결된 정점 개수 저장
	}
	for (int i = 0; i < M; ++i) {
		ll w; int x, y;
		scanf("%d%d%lld", &x, &y, &w);
		edge.push_back({ w,x,y});
	}
	sort(edge.begin(), edge.end(), greater<tuple<ll, int, int>>());
	
	for (tuple<ll, int, int>& e : edge) {
		
		ll w = get<0>(e);
		int a = get<1>(e); int b = get<2>(e);
#if DEBUG == true
		printf("cur tuple : %lld %d %d\n", w, a, b);
#endif
		merge(w, a, b);
	}

	for (int i = 1; i <= K; ++i) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}