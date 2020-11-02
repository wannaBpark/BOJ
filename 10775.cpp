#include <cstdio>
const int M = 1e5 + 10;
int G, P,ans=1;
int p[M],Rank[M] = { 0, };
int find(int a)	
{
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &G, &P);
	int ans = 0,a;
	for (int i = 1; i <= G; i++)
		p[i] = i;

	for (int i = 1; i <= P; i++) {
		scanf("%d", &a);
		if (find(a)) {
			p[p[a]] = p[p[a]] - 1;
		}
		else break;		
		++ans;
	}
	printf("%d\n", ans);	
	return 0;
}