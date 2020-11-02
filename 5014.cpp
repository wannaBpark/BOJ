#include <cstdio>
#include <queue>
#define MAX 1000000
using namespace std;
int F, S, G, U, D,ans;
queue<int> q;
int stair[MAX + 1] = { 0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
	q.push(S);
	stair[S] = 1; //어차피 출력할때 1빼주므로 1로해도됌.
	int dir[2] = { U,-D };
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == G) break;
		for (int i = 0; i < 2; i++) {
			int next = cur + dir[i];
			if (next > F || next < 1 || stair[next]) continue;
			stair[next] = stair[cur] + 1;
			q.push(next);
		}
	}
	/*
	if (S == G) {
		printf("0\n"); return 0;   //위의 주석에서 1빼므로 필요없는 예외처리
	}*/
	!stair[G] ? printf("use the stairs\n"):  printf("%d\n", stair[G]-1);
	return 0;
}