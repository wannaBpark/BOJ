#include <cstdio>
#include <vector>
#include <algorithm>
#define L 300100
#define swap(a,b) {auto tmp = a; a=b; b=tmp;}
using namespace std;
vector<pair<int,int>> v;
int N,a,b,D,G;
int deg[L];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		scanf("%d%d", &a, &b);
		v.push_back({ a,b });
		++deg[b], ++deg[a];
	}
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		if(deg[x]>=2 && deg[y]>=2) D += (deg[x] - 1) * (deg[y] - 1);
	}
	for (int i = 1; i <= N; i++) {
		if (deg[i] >= 3) G += deg[i] * (deg[i] - 1) * (deg[i] - 2) / 6;
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", deg[i]);
	puts("");
	if (D > 3 * G) puts("D");
	else if (D < 3 * G) puts("G");
	else if(D == 3*G) puts("DUDUDUNGA");	
	printf("%d %d\n", D, G);
	return 0;
}