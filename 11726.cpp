#include <stdio.h>
#define NAMU 10007
int N;
long long int DP[1001] = { 0, };
///f(i) = f(i-1) +f(i-2)
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	DP[1] = 1; DP[2] = 2;
	if (N>=3) {
		for (int i = 3; i <= N; i++) {
			DP[i] = (DP[i - 1] + DP[i - 2])%NAMU; //Q.�Ѳ����� ������ �����ߴٰ� ���۳���.�ͱ�?
		}
	}
	printf("%lld\n", DP[N]);
	//���� divide�ϴ� ���� �������鼭 ����� ��츦 ���Ϸ��������� �ߺ��߻�
	//�ߺ��߻��ϴ� ������ �ſ� �ָ�����
	//�������� �����ؼ� �ߺ��� �Ͼ�� �ʰ� �ϴ� ���� DP�� ����
	/*DP[1] = 1;
	DP[2] = 2;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < i; j++) {

		}
		ans += DP[i] + DP[N - i];
	}*/
	return 0;
}