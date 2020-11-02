#include <cstdio>
#include <algorithm>
#include <map>
#define MAX 500000
using namespace std;
int A[MAX + 10];
map<int, int> chk;
int N, M, a;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	sort(A, A + N);
	scanf("%d", &M);
	while (M--) {
		scanf("%d", &a);
		if (chk[a]) {
			printf("%d ", chk[a]); continue;
		}
		int start = 0, end = N,ans=0;
		while (start < end) {
			int mid = (start + end) / 2;
			if (A[mid] < a) start = mid + 1;
			else end = mid;
		}
		for (int i = end; i < N; i++) {
			if (A[i] != a) break;
			else ans++;
		}
		chk[a] = ans;
		printf("%d ", ans);
	}
	return 0;
}