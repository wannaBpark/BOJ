#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int ans = 0;
string S;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);
    cin >> N >> S;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < N; ++i) {
        auto& cur = S[i];
        if (cur == '(') {
            st.push(i);
        } else {
            st.pop();
            // wrong brace string
            if (st.empty()) {
                st.push(i);
            } else {
                ans = max(ans, i - st.top());
            }
        }        
    }
    cout << ans;
    return 0;
}