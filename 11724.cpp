#include <cstdio>
int p[1001], Rank[1001] = { 0, };
int chk[1001];
int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	if (Rank[a] == Rank[b]) { p[a] = b,++Rank[b]; }
	else if (Rank[a] < Rank[b]) p[a] = b;
	else p[b] = a;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int N, M,u,v;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) { p[i] = i; }
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &u, &v); merge(u, v);
		//printf("%d %d\n", find(u), find(v));
	}
	for (int i = 1; i <= N; i++) {
		chk[find(i)] = 1;
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (chk[i]) ++sum;
	}
	printf("%d\n", sum);
	return 0;
}