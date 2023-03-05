#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#define ll long long
#define OUTPUT 0

void Wdijkstra();
void Fdijkstra();

struct Wnode {
	int odd;
	int to;
	ll dist;
	Wnode(int o, int t, int d) {
		odd = o;
		to = t;
		dist = d;
	}
	bool operator<(const Wnode& i) const{
		//if (odd == i.odd) {
			if (dist == i.dist) {
				if (to == i.to) {
					return odd < i.odd;
				}
				return to > i.to;
			}
			return dist > i.dist;
		/*}
		return odd < i.odd;*/
	}
};
struct node {
	int to;
	ll dist;
};


int N, M, ans = 0;
ll Wdist[2][4010];
ll Fdist[4010];
ll INF = 2e9;

using namespace std;
vector<node> v[4010];

int main()
{
	scanf("%d%d", &N, &M);

	int a, b, d;
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &a, &b, &d);
		d *= 2;
		v[a].push_back({ b,d });
		v[b].push_back({ a,d });
	}

	for (int i = 1; i <= N; ++i) {
		Fdist[i] = Wdist[0][i] = Wdist[1][i] = INF;
	}

	Fdijkstra();
	Wdijkstra();

	for (int i = 2; i <= N; ++i) {
		if (Fdist[i] == INF) continue;
		ans += (Fdist[i] < min(Wdist[0][i], Wdist[1][i])) ? 1 : 0;
	}

	printf("%d", ans);
	return 0;
}

void Fdijkstra()
{
	priority_queue<pair<ll, int>> pq;
	//우선순위를 거리가 아니라 node에 두고잇엇음 바보같이 ㅁㄴㅇㄻㄴㅇㄹ
	Fdist[1] = 0;
	pq.push(make_pair( 0, 1 ));
	while (!pq.empty()) {
		int cur = pq.top().second;
		ll distance = -pq.top().first;
		pq.pop();
#if OUTPUT
		printf("cur : %d distance : %lld\n", cur, distance);
#endif
		if (Fdist[cur] < distance) continue;

		for (int i = 0; i < v[cur].size(); ++i) {
			int nxt = v[cur][i].to;
			ll nxtDist = v[cur][i].dist + Fdist[cur];

			if (nxtDist < Fdist[nxt]) {
				Fdist[nxt] = nxtDist;
				pq.push(make_pair(-nxtDist, nxt) );
			}
		}
	}
#if OUTPUT
	for (int i = 1; i <= N; ++i) {
		printf("%lld ", Fdist[i]);
	}
	puts("");
	puts("");
#endif

	
}

void Wdijkstra()
{
	priority_queue<pair<pair<ll, int>, int>> pq;

	Wdist[0][1] = 0;
	pq.push(make_pair(make_pair(0, 1), 0));

	while (!pq.empty()) {
		pair<pair<ll, int>, int> p = pq.top();
		int odd = p.second;
		int cur = p.first.second;
		ll distance = -p.first.first;

		pq.pop();
#if OUTPUT
		printf("odd : %d cur : %d distance : %lld\n", odd, cur, distance);
#endif
		if (Wdist[odd][cur] < distance) continue;

		for (int i = 0; i < v[cur].size(); ++i) {
			int nxt = v[cur][i].to;
			int nxtDist = Wdist[odd][cur];
			int d = v[cur][i].dist;
			nxtDist += (odd == 0) ? d / 2 : d * 2;
			if (nxtDist < Wdist[!odd][nxt]) {
				Wdist[!odd][nxt] = nxtDist;
				pq.push(make_pair(make_pair(-nxtDist, nxt), !odd));
			}
		}
	}
#if OUTPUT
	for (int i = 0; i <=1; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%lld ", Wdist[i][j]);
		}
		puts("");
	}

	puts("");
#endif
}