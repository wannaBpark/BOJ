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
		printf("0"); //�迭�� ������ S���� ������ �� �����ʿ䵵 ����
		return 0;
	}
	while ( !(end == N && (end - start + 1) == ans) && start<=N) { //start N�ʰ� ����ó��+end�� N�϶� �� �غ��� ans�� �ּ��� ���ó��
		while ( (P[end]-P[start-1] ) < S && end<N) { //end N�ʰ� ����ó�� + �ּڰ�S���������� end����
			++end;
		}
		if( (P[end]-P[start-1]) >= S) //S���� ũ�ų� ������ ans��,if�� ���� ������ end>=N�϶� while�� ����ؼ� ���� ���� �ֱ� ����.
			ans = ((end - start + 1) < ans) ? (end - start+1) : ans;
		++start;
	}
	printf("%d\n", ans);
	return 0;
}