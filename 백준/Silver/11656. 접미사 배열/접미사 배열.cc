#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<string> v;
string S;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);
    cin >> S;
    size_t end = S.length() - 1;
    for (size_t i = 0; i <= end; ++i) {
        string sub = S.substr(i);
        v.push_back(sub);
    }
    sort(v.begin(), v.end());
    for (auto s : v) cout << s << '\n';
    return 0;
}