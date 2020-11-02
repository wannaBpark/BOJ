#include <stdio.h>
long long P[100001] = { 0, };
long long A[100001] = { 0, };
int N, S,start=1,end=1;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &S);
	int ans = N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		P[i] = A[i];
	}
	for (int i = 1; i <= N; i++) {
		P[i] += P[i - 1];
		//printf("%d ", P[i]);
	}
	if (P[N] < S) {
		printf("0"); //배열의 총합이 S보다 작으면 더 구할필요도 없음
		return 0;
	}
	while ( !(end == N && (end - start + 1) == ans) && start<=N) { //start N초과 예외처리+end가 N일때 더 해봤자 ans가 최소인 경우처리
		while ( (P[end]-P[start-1] ) < S && end<N) { //end N초과 예외처리 + 최솟값S넘을때까지 end증가
			++end;
		}
		if( (P[end]-P[start-1]) >= S) //S보다 크거나 같을때 ans비교,if문 넣은 이유는 end>=N일때 while문 통과해서 왔을 수도 있기 때문.
			ans = ((end - start + 1) < ans) ? (end - start+1) : ans;
		++start;
	}
	printf("%d\n", ans);
	return 0;
}