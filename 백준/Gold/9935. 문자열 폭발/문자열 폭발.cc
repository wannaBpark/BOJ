#include <bits/stdc++.h>
using namespace std;
using ll = long long;

stack<char> st;
string ans;
string s;
string bomb;
vector<int> v;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> s >> bomb;
    int l = bomb.length();
    int sz = s.length();
    ans.reserve(1e6);
    for (int i =0; i<sz; ++i) {
        st.push(s[i]);
        if(bomb[l-1] == s[i] && st.size() >= l) {
            string tmp;
            int len = l;
            while (len--) {
                tmp.push_back(st.top());
                st.pop();
            }
            reverse(tmp.begin(), tmp.end());
            if (tmp.compare(bomb) != false) {
                for (int i =0; i<l; ++i) {
                    st.push(tmp[i]);
                }  
            } 
        }
    }
    if (st.size() == 0) cout << "FRULA";
    else {
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}