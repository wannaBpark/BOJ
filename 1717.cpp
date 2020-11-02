#include <cstdio>
#define MIN(a,b) (a<b) a:b;
#define swap(a,b) {auto tmp=a; a=b; b=tmp;}
#define MAX 1000001
int p[MAX],size[MAX],Rank[MAX];
int N, M;
int find(int a) 
{
	if (a == p[a]) return a;
	return p[a] = find(p[a]); //최악의 경우는 10의 6승 path compression
	
}
void uni(int a, int b) 
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (Rank[a] == Rank[b]) {
		p[a] = b;  ++Rank[b];
	}
	else if(Rank[a] < Rank[b]) p[a] = b;
	else p[b] = a;
}
void merge(int a, int b) 
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (size[b] > size[a]) swap(a, b);
	p[b] = p[a];
	size[a] += size[b];
}

int main()
{	
	scanf("%d%d", &N, &M);
	for (int i = 0; i <= N; i++) {
		Rank[i] = 0;
		size[i] = 1;
		p[i] = i;
	}
	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b,&c);
		if (a == 0) uni(b, c);
		else if (a == 1) printf(find(b) == find(c) ? "YES\n" : "NO\n");
		//자기자신의 현재 부모가 그것의 대푯값이 아닐수도 있다.
		
	}
	return 0;
}