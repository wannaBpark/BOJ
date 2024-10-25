#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sz1 = 0, sz2 = 0;
int N,cur;
priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int> max_heap;
void solve() {

    if (min_heap.empty() && max_heap.empty()) {
        max_heap.push(cur);
        sz1++;
        return;
    }
    if (max_heap.top() >= cur) {
        int tmp = max_heap.top(); max_heap.pop();
        max_heap.push(cur);
        min_heap.push(tmp);
        sz2++;
    } else if (max_heap.top() < cur) {
        min_heap.push(cur);
        sz2++;
    }
    if (sz1 - sz2 >= 2) {
        int tmp = max_heap.top();
        max_heap.pop();
        min_heap.push(tmp);
        sz1--;
        sz2++;
    } else if (sz2 - sz1 >= 2) {
        int tmp = min_heap.top();
        min_heap.pop();
        max_heap.push(tmp);
        sz1++;
        sz2--;
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    cin >> N;
    for (int i = 1; i<=N; ++i) {
        cin >> cur;
        solve();
        if (i % 2 == 1) {
            int ans = sz1>sz2 ? max_heap.top() : min_heap.top();
            cout << ans << '\n';
        } else {
            int ans = (max_heap.top()<min_heap.top()) ? max_heap.top() : min_heap.top();
            cout << ans << '\n';
        }
    }
    return 0;
}