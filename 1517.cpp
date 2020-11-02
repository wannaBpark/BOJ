#include <cstdio>
#include <algorithm>
#define MAX_N 1000000
using namespace std;
int N;
long long ans = 0;
int A[MAX_N];
int sorted[MAX_N];
void dc(int l, int r)
{
	if (r - l <= 0) return; //현재 배열의 개수가 1개 이하일 때.
	int mid = (l + r) / 2;
	dc(l, mid);
	dc(mid+1, r);
	int i = l, j = mid + 1, index = l;
	while (i <= mid && j <= r) {
		if (A[i] <= A[j]) { //swap 안일어남
			sorted[index++] = A[i++];
		}
		else {
			ans +=abs((long long)j - (long long)index);
			sorted[index++] = A[j++];
		}
	}
	while (i <= mid) { //왼쪽 배열에 원소 남아있을 경우
		sorted[index++] = A[i++];
	}
	while (j <= r) { //오른쪽 배열에 원소 남아있을 경우
		sorted[index++] = A[j++];
	}
	for (int k = l; k <= r; k++) A[k] = sorted[k];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &N); 
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	dc(0, N- 1);
	/*for (int i = 0; i < N; i++)
		printf("%d\n", sorted[i]);*/
	//for (int i = 500000; i >= 1; i--) printf("%d\n", i);
	printf("%lld\n", ans);
	return 0;
}