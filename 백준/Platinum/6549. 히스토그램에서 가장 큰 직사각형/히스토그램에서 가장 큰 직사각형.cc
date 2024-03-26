#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static inline ll max(ll a, ll b) {
    return a >= b ? a : b;
}

stack<int> st;
ll h[100010];

ll mx = 0;
int n, i;
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);

    while (true) {
        cin >> n;
        if (n == 0) break;

        for (i = 0; i < n; ++i)
            cin >> h[i];
    
        for (i = 0; i < n; ++i) {
            auto nxtIdx = i;

            while (!st.empty() && h[st.top()] > h[i]) {
                ll width = i;
                ll height = h[st.top()];
                st.pop();

                if (!st.empty()) {
                    // cout << "Before : " << width << " " << st.top() << endl;
                    width = (i - 1) - st.top(); 
                    // 내 바로 직전까지 너비까지, st.top의 높이로 직사각형 만들 수 있다.
                }
                mx = max(mx, width * height);

                // cout << i << " widdth : " << width << " h : " <<  height << endl;
            }

            st.push(nxtIdx);
        }

        while (!st.empty()) {
            ll width = n;
            ll height = h[st.top()];

            st.pop();

            if (!st.empty())
                width = (n - 1) - st.top();

            mx = max(mx, width * height);

            // cout << i << " width : " << width << " h : " <<  height << endl;
        }

        cout << mx << "\n";
        mx = 0;
    }

    return 0;
}
