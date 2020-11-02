#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 40000000;
int N;
char S[10][101];
int c = 0;
int cnt = MAX;
int ans = 0;
void pretest(char S[])
{
	for (int i = 0; i < strlen(S) - 1; i++) {
		ans += (S[i] == S[i + 1]) ? 0 : 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	vector<int>v(N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &S[i]);
		pretest(S[i]);
	} 
	for (int i = 0; i < N; i++) {
		v[i] = i;
	}
	do {
		c = 0;
		for (int i = 0; i < N-1; i++) {
			int tmp = v[i]; int next = v[i + 1];
			int fore = strlen(S[tmp]); 
			c += (S[tmp][fore-1] == S[next][0]) ? 0 : 1;
		}
		/*for (int i = 0; i < N; i++) {
			printf("%d ", v[i]);
		}
		puts("");*/
		cnt = (c < cnt) ? c : cnt;
	} while (next_permutation(v.begin(), v.end()));
	if (cnt < MAX) ans += cnt;
	printf("%d\n", ans);
	return 0;
}