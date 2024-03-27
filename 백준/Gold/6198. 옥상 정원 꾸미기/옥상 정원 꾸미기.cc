#include <bits/stdc++.h>
using namespace std;
using ll = long long;

stack<int> st;
ll h[80010];
ll ans = 0, tmp;
int n, i;
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
    cin >> n;
    for (i = 0; i < n; ++i) cin >> h[i];

    for (i = 0; i < n; ++i)
    {
        tmp = 0;
        while (!st.empty() && h[st.top()] <= h[i])
        {
            tmp++;
            st.pop();
        }
        
        if (!st.empty()) {
            ans += ll(st.size()) * tmp;
        }
        ans += (tmp - 1) * tmp / 2;
        
        st.push(i);
    }
    tmp = 0;
    while (!st.empty()) {
        st.pop();
        ++tmp;
    }
    ans += (tmp - 1) * tmp / 2;
    cout << ans;
    return 0;
}
