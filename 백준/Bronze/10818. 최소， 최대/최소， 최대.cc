#include <stdio.h>
int N;
int i = 0;
int input;
int min = 1e8;
int max = -1e8;
int main()
{
	scanf("%d", &N);

	do {
		scanf("%d", &input);

		if (min > input) {
			min = input;
		}

		if (max < input) {
			max = input;
		}

	} while (++i < N);

	printf("%d %d", min, max);
	return 0;
}