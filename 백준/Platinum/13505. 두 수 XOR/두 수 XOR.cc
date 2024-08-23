#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct Trie{
    Trie* nxt[2]; // 2-digit
    bool finish;

    Trie(): finish(false) {
        memset(nxt, 0, sizeof(nxt));
    }

    ~Trie() {
        for (int i = 0; i < 2; ++i) if (nxt[i]) delete nxt[i];
    }

    void insert(int key, int digit) {
        if (digit < 0) {
            finish = true;
            return;
        }
        int cur = key & (1 << digit);
        if (cur) cur = 1;
        if (nxt[cur] == nullptr)
            nxt[cur] = new Trie();
        
        nxt[cur]->insert(key & ~(1 << digit), digit - 1);
    }

    int solve(int key, int digit) {
        if (digit < 0) return 0;
        int cur = key & (1 << digit);
        if (cur) cur = 1;
        cur = (cur + 1) % 2; // XOR : 다르면 1의 출력이 나옴
        
        int ret = 0;
        if (nxt[cur] == nullptr) cur = (cur + 1) % 2;
        else ret = 1 << digit;
        
        return ret + nxt[cur]->solve(key & ~(1 << digit), digit - 1);
    }
};

int arr[(size_t)1e5+10];
int N;
int ans = 0;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    Trie* p_root = new Trie();
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        p_root->insert(arr[i], 31);
    }

    for (int i = 0; i < N; ++i) {
        ans = max(ans, p_root->solve(arr[i], 31));
    }
    cout << ans;
    return 0;
}