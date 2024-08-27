#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Trie {
    Trie *nxt[2];
    int cnt;

    Trie() : cnt(0) {
        nxt[0] = nxt[1] = nullptr;
    }

    ~Trie() {
        for (int i = 0; i < 2; ++i) if (nxt[i]) delete nxt[i];
    }
};

void push(Trie *p_root, int val) {
    Trie *p_cur = p_root;
    for (int i = 30; i >= 0; --i) {
        int bit = val & (1 << i);
        if (bit) bit = 1;
        if (p_cur->nxt[bit] == nullptr) p_cur->nxt[bit] = new Trie();
        p_cur = p_cur->nxt[bit];
        p_cur->cnt += 1;
        // cout << i << " " << bit << '\n';
    }
}

void pop(Trie *p_root, int val) {
    Trie *p_cur = p_root;
    for (int i = 30; i >= 0; --i) {
        int bit = val & (1 << i);
        if (bit) bit = 1;
        p_cur = p_cur->nxt[bit];
        p_cur->cnt -= 1;
    }
}

int print(Trie *p_root, int val) {
    int ret = 0;
    Trie *p_cur = p_root;
    for (int i = 30; i >= 0; --i) {
        int bit = val & (1 << i); // x의 i번째 비트
        if (bit) bit = 1;
        int inv = (bit + 1) %2;
        // cout << i << " bit" << bit << " inverse: " << inv <<'\n';
        if (p_cur->nxt[inv] && p_cur->nxt[inv]->cnt > 0) {
            ret += (1 << i);
            p_cur = p_cur->nxt[inv];
        } else {
            p_cur = p_cur->nxt[bit];
        }
    }
    return ret;
}

int M;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);
    Trie* p_root = new Trie();
    push(p_root, 0);
    cin >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        switch (a) {
        case 1: push(p_root, b); break;
        case 2: pop(p_root, b); break;
        case 3: cout << print(p_root, b) << '\n'; break;
        }
    }
    return 0;
}