#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<string> v;
string S;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> S;
    int end = S.length() - 1;
    for (int i = 0; i <= end; ++i) {
        string sub = S.substr(i);
        v.push_back(sub);
        // cout << "sub: " << sub << '\n';
    }
    sort(v.begin(), v.end());
    for (auto s : v) cout << s << '\n';
    return 0;
}