#include <cstdio>
#include <cstring>
char S[110];
int cnt = 0,ans=0;
int main()
{
	scanf("%s", &S);
	int i, j,cnt=1;
	for (int i = 1; i < strlen(S); i++) {
		if (S[i] - S[i - 1] == 1) {
			cnt++;
		}
		else if (cnt == 3) {
			cnt = 1; ans++;
		}
		else cnt = 1;
	}
	if (cnt == 3) ans++;
	printf("%d\n", ans);
	return 0;
	//4개 연속한건 뭐함?
}