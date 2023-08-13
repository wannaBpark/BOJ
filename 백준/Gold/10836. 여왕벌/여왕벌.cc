#include<stdio.h>

#define max(X,Y) (((X) > (Y)) ? (X) : (Y))

int N, M;
int dp[710][710];

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++)dp[i][j] = 0;
	}

	for (int i = 0; i < N; i++) {
		int d, d1, d2;
		scanf("%d %d %d", &d, &d1, &d2);

		for (int j = M - 1; j >= 0; j--) {
			if (d2) {
				dp[0][j] += 2;
				d2--;
			}
			else if (d1) {
				dp[0][j] += 1;
				d1--;
			}
			else break;
		}

		for (int j = 1; j < M; j++) {
			if (d2) {
				dp[j][0] += 2;
				d2--;
			}
			else if (d1) {
				dp[j][0] += 1;
				d1--;
			}
			else break;
		}
	}

	for (int j = 0; j < M; j++) {
		for (int k = 0; k < M; k++) {
			if (j > 0 && k > 0) {
				dp[j][k] = dp[j - 1][k];
			}
			printf("%d ", dp[j][k]+1);
		}
		printf("\n");
	}


	return 0;
}