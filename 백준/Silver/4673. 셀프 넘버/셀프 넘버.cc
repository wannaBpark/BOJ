#include <bits/stdc++.h>
using namespace std;

int Ans[10010];

void SelfNumber(int n)
{
    int sum = n;
    while (n) {
        sum += n % 10;
        n /= 10;
    }

    if (sum <= 10000) {
        Ans[sum] = 1;
    }
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    for (int i = 1; i<= 10000; ++i) {
        SelfNumber(i);
    }

    for (int i = 1; i<= 10000; ++i) {
        if (Ans[i] == 0) {
            cout << i << '\n';
        }
    }

    return 0;
}