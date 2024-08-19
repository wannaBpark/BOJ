#include <bits/stdc++.h>
using namespace std;

const static int N_ALPHA = 26;

struct Trie{
    Trie* nxt[N_ALPHA];
    bool finish;

    Trie(): finish(false) {
        for (int i = 0; i< N_ALPHA; ++i) {
            nxt[i] = NULL;
        }
    }

    ~Trie() {
        for (int i = 0; i < N_ALPHA; ++i) {
            if (nxt[i]) // un freed memory exists
                delete nxt[i];
        }
    }

    void insert(const char* p_str) {
        if (*p_str == '\0') {// end of the string 
            finish = true;
            return;
        }
        int cur = *p_str - '0';
        if (nxt[cur] == NULL){
            nxt[cur] = new Trie();
        }
        nxt[cur]->insert( p_str + 1 ); // insert next character
    }

    bool find(const char* p_str) {
        if (*p_str == '\0') {
            return false;
        }
        if (finish == true) return true;

        int cur = *p_str - '0';
        if (nxt[cur] == NULL) {
            return false;
        } else {
            return nxt[cur]->find( p_str + 1);
        }
    }
};

char word[100010][15];
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        Trie* p_root = new Trie();
        int ret = true;

        for (int i =0; i < N; ++i) {
            cin >> word[i];
            p_root->insert(word[i]);
        }
        for (int i = 0; i < N; ++i) {
            ret = p_root->find(word[i]);
            if (ret == true) { // 중간에 끝이나는 string이 존재한다 (find == true)
                // cout << word[i] << '\n';
                break;
            }
        }
        ret == false ? puts("YES") : puts("NO");
    }
    return 0;
}