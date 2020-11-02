#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[201];
int N, M, ans = 0, cnt = 0;
int pick[4];
int check()
{
	for (int i = 1; i <= 3; i++) {
		int x = pick[i];
		for(int )
	}
}
void dfs(int index, int length)
{
	if (length == 4) {
		if (check()) ++ans;
		return;
	}
	if (index > N) return;
	pick[index] = index;
	dfs(index + 1, length + 1); //선택함
	dfs(index + 1, length); //선택안함
}
int main()
{
	scanf("%d%d", &N, &M);
	int a, b;
	while (M--) scanf("%d%d", &a, &b), v[a].emplace_back(b), v[b].emplace_back(a);
	dfs(1, 0); printf("%d\n", ans);
	return 0;
}