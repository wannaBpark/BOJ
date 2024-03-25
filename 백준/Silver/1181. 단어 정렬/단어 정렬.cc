#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> v;
size_t n;

static inline bool compare(string& s1, string& s2) {
    if (s1.size() == s2.size())
        return s1 < s2;
    else
        return s1.size() < s2.size();
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto& s : v) cout << s << endl;
    return 0;
}