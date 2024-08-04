#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[1010][1010];
char s1[1010];
char s2[1010];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> s1 >> s2;
    auto len1 = strlen(s1);
    auto len2 = strlen(s2);
    for (int i = len1 + 1; i >= 1; --i) {
        s1[i] = s1[i-1];
        dp[i][0] = i;
    }
    for (int i = len2 + 1; i >= 1; --i) {
        s2[i] = s2[i-1];
        dp[0][i] = i;
    }
    // 문자열 1번지부터 시작하도록 전처리

    for (int r = 1; r <= len1; ++r) {
        for (int c = 1; c <= len2; ++c) {
            if (s1[r] == s2[c]) {
                dp[r][c] = dp[r-1][c-1];                
            } else {
                dp[r][c] = min(dp[r-1][c], min(dp[r][c-1], dp[r-1][c-1])) + 1; 
            }
        }
    }
    cout << dp[len1][len2];

    return 0;
}