#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, K;
queue<int> q;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        q.push(i+1);        
    }
    
    cout << "<";
    while (!q.empty()) {
        for (int i =1; i < K; ++i) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        if (q.size() != 1) {
            cout << ", ";
        }
        q.pop();
    }
    cout << ">";

    return 0;
}