#include <cstdio>
int N;
int main()
{
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i) {
        printf("%d ", 2*i - 1);
    }

    return 0;
}