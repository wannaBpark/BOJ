#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static inline ll max(ll a, ll b)
{
    return a >= b ? a : b;
}

stack<int> st;
ll h[80010];
ll sum[80010];
ll ans = 0;
ll ans2 = 0;
ll tmp;
int n, i;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> h[i];

    for (i = 0; i < n; ++i)
    {
        auto cur = i;
        tmp = 0;
        while (!st.empty() && h[st.top()] <= h[i])
        {
            tmp++;
            ll curLowest = st.top();
            st.pop();
            ll curTop = (st.empty()) ? 0 : st.top();

            ll cnt = curLowest - curTop; //Gurantee it's all monotonic low before cur

            ans += cnt;

            sum[curTop] += 1;

            
            // cout << "curTop and Low : " << curTop <<" " << curLowest<< " " << ans<< "\n";
            // cout << "i : " << cur <<" " <<cnt << " " << ans<< "\n";
        }
        if (st.empty()) {
            tmp -= 1;
            ans2 += (tmp + 1) * tmp / 2;  
        } else {
            ans2 += ll(st.size()) * tmp;
            ans2 += (tmp - 1) * tmp / 2;
            // if(tmp>0) 
            // cout << "SIZE: " << st.size() << endl;
        }
              
        
        // cout << "i: " << i <<" TMP : " << tmp << " ANS2 : " << ans2 << endl;
        st.push(cur);
    }

    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", sum[i]);
    // }
    // puts("");
    tmp = 0;
    while (!st.empty()) {
        ll curLowest = st.top();
        st.pop();
        ll curTop = (st.empty()) ? 0 : st.top();

        ll cnt = curLowest - curTop; //Gurantee it's all monotonic low before cur

        ans += cnt;
        sum[curTop] += 1;
        ++tmp;
        
        // cout << "curTop and Low : " << curTop <<" " << curLowest<< " " << ans<< "\n";

    }
    ans2 += (tmp - 1) * tmp / 2;
    // cout << "TMP : " << tmp << " ANS2 : " << ans2 << endl;
    

    cout << ans2;

    return 0;
}
