#include <cstdio>
#include <queue>
#include <vector>
#define MAX_N 1001
using namespace std;


int N, K,TC;

int main()
{
	//freopen("input.txt", "r", stdin);
	int a, b; 
	scanf("%d", &TC);
	
	while (TC--) {
		int IN[1001] = { 0, };
		vector<int> gph[MAX_N];
		queue<int> q;
		int cost[MAX_N] = { 0, };
		int max_cost[MAX_N] = { 0, };

		scanf("%d%d", &N, &K);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &cost[i]);
		}
		for (int i = 0; i < K; i++) {
			scanf("%d%d", &a, &b);
			gph[b].emplace_back(a); 
			IN[b] = max(IN[a] + 1,IN[b]);
		}
		int eFlag;
		for (int i = 1; i <= N; i++) {
			//printf("%d ", IN[i]);
			if (!IN[i]) eFlag = i;
		}
		//printf("\n"); 
		int wFlag; scanf("%d", &wFlag);
		int cur_indegree = IN[wFlag];
		/*for (int i = 1; i <= N; i++)
			if (!IN[i]) */ //원래:Indegree = 0 -> 시작노드이다.
		q.push(wFlag);
		max_cost[IN[wFlag]] = cost[wFlag]; 
		max_cost[0] = cost[eFlag];
		while (!q.empty()) {
			int next_node = q.front(); q.pop();
			//printf("%d ", next_node);
			for (int i = 0; i < gph[next_node].size(); i++) {
				if (cur_indegree && gph[next_node][i] != 1) {
					int tmp = gph[next_node][i];
					max_cost[IN[tmp]] = max(max_cost[IN[tmp]], cost[tmp]);

					q.push(gph[next_node][i]);
				}
			}
			cur_indegree--;
		}
		int ans = 0;
		for (int i = 0; i <= IN[wFlag]; i++) {
			ans += max_cost[i];
			//printf("maxcost[%d] : %d\n", i, max_cost[i]);
		}
		
		printf("%d\n",ans);
	}
	return 0;
}