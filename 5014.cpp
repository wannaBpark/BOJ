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
	stair[S] = 1; //������ ����Ҷ� 1���ֹǷ� 1���ص���.
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
		printf("0\n"); return 0;   //���� �ּ����� 1���Ƿ� �ʿ���� ����ó��
	}*/
	!stair[G] ? printf("use the stairs\n"):  printf("%d\n", stair[G]-1);
	return 0;
}