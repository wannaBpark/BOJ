#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[1001];
int N, M;
int A[1001][1001];
int visited[1001] = { 0 };
int ans = 0;
void dfs(int s)
{
	visited[s] = true;
	for (int i = 0; i < v[s].size(); i++) {
		if (!visited[v[s][i]]) dfs(v[s][i]);
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	int a, b;
	while (M--) scanf("%d%d", &a, &b),v[a].emplace_back(b),v[b].emplace_back(a);
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i), ++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}