#include <bits/stdc++.h>
#define MAX_N 1010
using namespace std;
using ll = long long;

int N, K,TC;
int main()
{
	int a, b; 
	scanf("%d", &TC);
	
	while (TC--) {
		vector<int> gph[MAX_N];
		queue<int> q;
		int W;
		int IN[MAX_N] = { 0, };
		int cost[MAX_N] = { 0, };
		int max_cost[MAX_N] = { 0, };

		scanf("%d%d", &N, &K);
		for (int i = 1; i <= N; i++) scanf("%d", &cost[i]);
		for (int i = 1; i <= K; i++) {
			scanf("%d%d", &a, &b);
			gph[a].push_back(b); 
			++IN[b];
		}
		for (int i = 1; i<= N; ++i) {
			if (!IN[i]) q.push(i); // indegree = 0 node push
		}
		scanf("%d", &W);
		
		// nxt건물 소요시간 = (선행 노드까지의 최대 건설시간 + 선행노드 건설시간)
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto nxt : gph[cur]) {
				int& nxtCost = max_cost[nxt];
				int curToNxt = cost[cur] + max_cost[cur]; 
				nxtCost = max(nxtCost, curToNxt);
				// printf("%d %d %d %d %d\n", cur, nxt, nxtCost, max_cost[cur], ans);
				if(--IN[nxt] == 0) q.push(nxt);
			}
		}		
		printf("%d\n",max_cost[W] + cost[W]);
	}
	return 0;
}