#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    string s,t;
    while(cin >> s >> t) {
        size_t i=0, j=0;
        size_t slen = s.length(), tlen = t.length();
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) i++, j++;
            else j++;
        }
        cout << ((i == s.length()) ? "Yes" : "No") <<'\n';
    }
    return 0;
}