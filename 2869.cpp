#include <cstdio>
#define min(a,b) a>b ? b: a
int A, B, V,start,ans,end;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &A, &B, &V);
	start = 0, ans = end = V;
	while (start<=end) {
		int mid = (start + end) / 2;
		printf("%d %d %d\n", start, end, mid);
		if (V <= mid*(A - B) + A) {
			ans = min(ans, mid + 1);
			end = mid - 1;
		}
		else start = mid + 1;
	}
	//(V-B)/(A-B) + 1
	printf("%d\n", ans);
	return 0;
}