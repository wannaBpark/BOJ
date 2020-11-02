
#include<cstdio>
#include <string>
int ans = 0, C[11],N;
int main()
{
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 12; i++) C[i] = -1;
	int a, b;
	scanf("%d", &N);
	while (N--) {
		scanf("%d%d", &a, &b);
		if (C[a] == -1) C[a] = b;
		if (C[a] != b) C[a] = b, ++ans;
	}
	printf("%d\n", ans);
	return 0;
}