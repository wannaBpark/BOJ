#include <cstdio>
#include <vector>
#include <queue>
#define MN 201000
using namespace std;
int N,a,b;
queue<int> q;
int IND[MN],ans[MN],edge[MN],Rank[MN],;
int child[MN];
vector<int> gph[MN];
//int find(int a, int rank) {
//	if (a == p[a]) return a;
//	else p[a] +=rank
//	return p[a] = find(p[a], rank + 1);
//}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	edge[0] = 1, edge[1] = 3;
	for (int i = 2; i <= N; i++) {
		scanf("%d", &a);
		gph[i].emplace_back(a), ++IND[a]; ++child[a];
		edge[i] = edge[i - 1] + (i + 1);
	}
	puts("");
	for (int i = N; i >=2; i--) {
		if (!IND[i]) q.push(i);
		printf("%d..\n", IND[i]);
	}
	int next;
	while (!q.empty()) {
		int cnt = 0;
		int x = q.front(); q.pop();
		ans[x] += edge[0];
		printf("%d\n", x);
		while (x != 1) {
			cnt++;
			x = gph[x][0]; Rank[x]=cnt;
		}
	}
	for (int i = 1; i <= N; i++) {
		//if (IND[i] >= 2) printf("%d ", ans[i] - IND[i]);
		//else printf("%d ", ans[i] - IND[i]);
	}
	return 0;
}