#include <cstdio>
#include <queue>
#include <vector>
#define MAX_N 32001
using namespace std;
vector<int> gph[MAX_N];
priority_queue<int> pq;
int IN[MAX_N] = { 0, };
int N, M,same=0;

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	int a, b,i,index=0,front,next_node,nx,nx_front;
	for (i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		gph[a].push_back(b);
		++IN[b];
	}
	for (i = 1; i <= N; i++)
		if (!IN[i]) pq.push(-i);
	while (!pq.empty()) {
		int next_node = pq.top(); pq.pop();
		printf("%d ", -next_node);
		for (int i = 0; i < gph[-next_node].size(); i++) {
			if (!(--IN[gph[-next_node][i]])) {
				pq.push(-gph[-next_node][i]);
			}
		}
	}

	return 0;
}