#include <cstdio>
#define MAX 201

int p[MAX], N, M, ans = 1, Rank[MAX] = { 0, },input[MAX][MAX];
int find(int a)
{
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (Rank[a] == Rank[b]) {
		p[a] = b; ++Rank[b];
	}
	else if (Rank[a] < Rank[b]) p[a] = b;
	else p[b] = a;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	int a, b, c;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j]) merge(i, j);
		}
	}
	scanf("%d", &a); --M;
	while (M--) {
		scanf("%d", &b); if (find(a) != find(b)) ans = 0;
		b = a;
	}
	printf(ans ? "YES\n" : "NO\n");
	return 0;
}