#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std; 
int N;
int A[110];
int visited[110];
vector<int> answer;
int search(int parent, int cur)
{
    if (parent == cur) return true;
    if (visited[cur] == true) return false;
    visited[cur] = true;
    return search(parent, A[cur]);
}
int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; ++i) {
        memset(visited, 0, sizeof(int) *(N + 1));
        visited[i] = search(i, A[i]);
        if (visited[i] == true) {
            answer.push_back(i);
        }
    }
    cout << answer.size() << endl;
    for (auto i : answer){
        cout << i << endl;
    }
    return 0;
}