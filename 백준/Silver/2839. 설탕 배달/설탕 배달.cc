#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int D[5010];
int N;
int dp(int i) {
    if (i<=0) return INF;
    int& ret = D[i];
    if (ret!=INF) return ret;

    ret = min(dp(i-3) + 1, ret);    
    ret = min(dp(i-5) + 1, ret);
    return ret;
}
int main()
{
    cin >>N;
    for (int i =1; i<=N; ++i) {
        D[i] = INF;
    }
    D[3] = D[5] = 1;
    int ret = dp(N);
    if (ret >= INF) ret = -1;
    cout << ret;
    return 0;
}