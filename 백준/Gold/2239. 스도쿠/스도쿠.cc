#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char A[10][10];
int chkgaro[10][10] = {0,};
int chksero[10][10] = {0,};
int chkquad[10][10] = {0,};

int getQuadurant(int i, int j);
void input();
void backtracking(int cur);
void print();
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    input();
    backtracking(0);
    return 0;
}

void backtracking(int cur) 
{
    int cx = cur/9; int cy = cur%9;
    int q = getQuadurant(cx,cy);
    if (cur >= 81) {
        print();
        exit(0);
    }
    if (A[cx][cy] != '0') {
        backtracking(cur + 1);
        return;
    }
    // if theres no [1,9] available in same quadurant, row, column
    // set A[cx][cy] = nxt, keep backtracking
    for (int nxt = 1; nxt <= 9; ++nxt) {
        if (!chkgaro[cx][nxt] && !chksero[cy][nxt] && !chkquad[q][nxt]) {
            chkgaro[cx][nxt] = chksero[cy][nxt] = chkquad[q][nxt] = true;
            A[cx][cy] = nxt + '0';
            backtracking(cur + 1);
            chkgaro[cx][nxt] = chksero[cy][nxt] = chkquad[q][nxt] = false;
            A[cx][cy] = '0';
        }
    }
}
void input() 
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> A[i][j];
            if (A[i][j] == '0') continue;
            char& c = A[i][j];
            int idx = c - '0';
            int q = getQuadurant(i, j);
            chkgaro[i][idx] = chksero[j][idx] = chkquad[q][idx] = true;
        }
    }
}

// return [0, 8]
int getQuadurant(int i, int j) {
    i /= 3; j /= 3;
    int ret = 3*i + j;
    return ret;
}

void print() 
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << A[i][j];
        }
        cout << '\n';
    }
}