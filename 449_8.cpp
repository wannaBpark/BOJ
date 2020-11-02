#include <cstdio>
#include <vector>
#include <map>
#define MAX 300000
using namespace std;
map<int, string> m;
int N, M, K, Q;
int x, y,num;
char c;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	while (K--) {
		scanf("%d %d %c", &x, &y, &c);
		v[x].emplace_back(make_pair(y,c ));
	}
	while (Q--) {
		scanf("%c %d", &c, &num);
		printf("%c %d\n", c, num);
	}
	return 0;
}