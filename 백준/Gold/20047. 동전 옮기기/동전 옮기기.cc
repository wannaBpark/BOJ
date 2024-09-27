#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, a,b;
string two;
string sub,T;
string S;
// dp[idx2][status] : T의 idx2번째 원소까지 봤을때, 동전을 status 개 이동하여
// 문자열 T[0:i]를 만들 수 있는지 여부
int dp[10010][3];

int go(int idx1, int idx2, int status) {
    int& ret = dp[idx2][status];
    if (ret != -1) {
        return ret;
    }

    if (idx2 == N) {
        // status = 2 -> 모든 동전 다 썼음
        return ret = (status == 2) ? true : false;
    }
    
    // 아직 방문하지 않았다면, -1 이다 -> 0으로 초기화시킴
    ret = 0;
    // T[idx2]에 배치하는 경우
    if (T[idx2] == two[status] && status < 2) {
        ret |= go(idx1, idx2 + 1, status + 1);
    }
    if (sub[idx1] == T[idx2] && idx1 < N - 2) {
        ret |= go(idx1 + 1, idx2 + 1, status);
    }
    
    return ret;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    memset(dp,-1, sizeof(dp));
    cin >> N;
    cin >> sub >> T;
    cin >> a >> b;
    
    two += sub[a]; two += sub[b];
    S = sub.substr();
    sub.erase(sub.begin() + a);
    sub.erase(sub.begin() + b-1);

    int ret = go(0, 0, 0);
    (ret == true) ? puts("YES") : puts("NO");
    return 0;
}