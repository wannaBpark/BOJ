#include <bits/stdc++.h>
using namespace std;
using ll = long long;

stack<int> st;
ll h[500010];
int ans[500010], tmp;
int n, i;
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
    cin >> n;
    for (i = 0; i < n; ++i) { 
        cin >> h[i]; 
        ans[i] = -1;
    }

    for (i = 0; i < n; ++i)
    {
        while (!st.empty() && h[st.top()] < h[i])
        {
            int cur = st.top();
            st.pop();

            if (!st.empty()){
                ans[cur] = st.top();
            }
        }
        
        st.push(i);
    }
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (!st.empty()) {
            ans[cur] = st.top();
        } else {
            break;
        }
    }
    
    for (i = 0; i < n; ++i) { 
        printf("%d ", (ans[i] == -1) ? 0 : ans[i] + 1);
    }

    return 0;
}
