#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int> max_heap;
int N, a;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> a;

        if (max_heap.size() == 0) {
            max_heap.push(a);
        } else {
            if (max_heap.size() > min_heap.size()) {
                min_heap.push(a);
            } else {
                max_heap.push(a);
            }

            int mxtop = max_heap.top();
            int mntop = min_heap.top();
            if (mxtop > mntop) {
                max_heap.pop();
                min_heap.pop();
                max_heap.push(mntop);
                min_heap.push(mxtop);
            }
        }
        cout << max_heap.top() << '\n';
    }
    return 0;
}