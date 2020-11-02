#include <stdio.h>
#define N 90
long long int DP[N+1];
//long long int q(int i)
//{
//	if (i == 1) return 0;
//	if (DP[i]!=NULL) return DP[i];
//	return DP[i] = q(i - 1) + q(i - 2);
//}
int main()
{
	freopen("input.txt", "r",stdin);
	int input;
	DP[0] = 0; DP[1] = 1;
	scanf("%d", &input);
	for (int i = 2; i <=input; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	printf("%lld\n", DP[input]);
	return 0;
}