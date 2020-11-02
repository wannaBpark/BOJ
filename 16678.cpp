#include <cstdio>
#include<algorithm>
using namespace std;
int N,x,index= 0,ans=0;
int sum = 0;
int A[101000];
int chk[101000];
int wyB[101000];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		sum += A[i];
	}
	int cnt = N*(N + 1) / 2;
	printf("%d %d\n", sum, cnt);
	printf("%d\n", sum - cnt);
	//return 0;
	sort(A, A + N);
	for (int i = 1; i <= N; i++) {
		printf("asdf    %d %d\n", A[i - 1], i);
		cnt += abs(A[i - 1] - i);
		ans += (A[i - 1] - 1);
	}
	printf("\n%d %d\n", cnt,ans);
	/*for (int i = 0; i < N; i++) {
		x = A[i];
		if (x <= N && !chk[x]) {
			chk[x] = 1; A[i] = 0;
		}
	}
	for(int i=0; i<N; i++) if(A[i]) wyB[index++] = A[i];
	int j = 0;
	for (int i = 1; i <= N; i++) {
		x = chk[i];
		if(x==0){
			ans += abs(i - wyB[j++]);
			printf("%d %d\n", i, wyB[j-1]);

		}
	}*/
	printf("%d", ans);
	return 0;
}