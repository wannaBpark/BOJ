#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, a;
int cur = 1;
ll sum = 0;
vector<int> v;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    
    
    for (int i = 0; i < N; ++i) {
        if (v[i] == cur) {
            ++cur;
        } else if (v[i] > cur) {
            sum += (v[i] - cur);
            ++cur;
        }
    }
    cout << sum;
    return 0;
}