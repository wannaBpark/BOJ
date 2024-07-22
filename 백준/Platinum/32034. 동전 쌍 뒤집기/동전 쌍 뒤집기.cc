#include <bits/stdc++.h>
using namespace std;
using ll=long long;
char S[1000010];
ll ans = 0;
int T,N,length;

void solve();

int main ()
{
    
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);
    cin>>T;
    while(T--) {
        cin >> N; cin >> S;
        length = N;
        ans = 0;
        solve();
    }
    return 0;
}
void solve()
{
    stack<int> s;
    for (int i =0; i < length; ++i) {
        if (S[i] == 'T') {
            if (s.empty() ||  (i - s.top()) % 2 == 0) {
                s.push(i);
            } else {
                ans += (i - s.top());
                s.pop();
            }
        }
    }
    cout << (ans = (s.empty()) ? ans : -1) << '\n';
}