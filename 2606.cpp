#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int s, e, N, M,ans=0;
int visited[101] = { 0 };
vector<int> v[101];
queue<int> q;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%d", &M);
	int a, b;
	while (M--) {
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b),v[b].emplace_back(a);
	}
	q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			if (!visited[v[cur][i]] && v[cur][i]!=1) q.push(v[cur][i]), visited[v[cur][i]] = 1;
		//위에것 : 다시 1로 돌아오거나, 이미 방문한 지점은 안간다.
		}
	}
	for (int i = 1; i <= N; i++)
		if (visited[i]) ++ans;
	printf("%d\n", ans);
	return 0;
}