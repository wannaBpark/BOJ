#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int T,N,length;
ll ans = 0;
char S[1000010];
void solve();
int main ()
{
    
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);
    cin>>T;
    while(T--) {
        cin >> N; cin >> S;
        length = N;
        solve();
    }
    return 0;
}
void solve()
{
    ans = 0;
    stack<char> s;
    stack<int> Hstack;
    int hCnt = 0; // 양끝 T 사이의 H 개수 저장 변수
    for (int i =0; i < length; ++i) {
        if (S[i] == 'T') {
            // 첫 번째 T : 무조건 { push
            // T가 이미 있는데, H 개수가 홀수일 때에는 뒤집을 수 없다 -> {를 하나더 push
            if (s.empty() || hCnt % 2 == 1) {
                s.push('{');
                Hstack.push(hCnt);
                hCnt = 0;
            }
            else if (hCnt % 2 == 0) { // T ('{')가 이미 있고, 해당 T로부터 H 개수가 짝수일 때
                s.pop();
                ans += (hCnt + 1);
                // {} 쌍을 맞추어 pop시킬때, 더 크게 감싸는 {가 없다면 hCnt = 0, 아니면 해당 hCnt값에 적절히 더해줌
                if (s.empty()) {
                    hCnt = 0;
                } else {
                    hCnt = Hstack.top() + hCnt + 2; Hstack.pop();
                }
            }
        } else if (S[i] == 'H') {
            if (s.empty()) continue;
            ++hCnt;
        }
    }
    ans = (s.empty()) ? ans : -1;
    cout << ans << '\n';
}
