#include <cstdio>
#include <queue>
#include <vector>
#define MAX_N 32001
using namespace std;
vector<int> gph[MAX_N];
queue<int> q;
int IN[MAX_N] = { 0, };
int N, M;

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		gph[a].push_back(b);
		++IN[b];
	}
	for (int i = 1; i <= N; i++)
		if (!IN[i]) q.push(i);
	while (!q.empty()) {
		int next_node = q.front(); q.pop();
		printf("%d ", next_node);
		for (int i = 0; i < gph[next_node].size(); i++) {
			if (!(--IN[gph[next_node][i]])) {
				q.push(gph[next_node][i]);
			}
		}
	}
	
	return 0;
}