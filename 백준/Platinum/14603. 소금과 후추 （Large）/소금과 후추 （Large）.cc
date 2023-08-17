#include <bits/stdc++.h>
#define MX_N 310
#define MX_K 1e5
#define fastio cin.tie(0)->sync_with_stdio(0)
#define x first
#define y second
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;

int Fenwick_Tree[100020];

int MX_INPUT = -1;
int median;
int M, N, K, W;
int arr[MX_N][MX_N];
int cnt[100010];
// int tree[MX_K];
int ans[MX_N][MX_N];

int Sum(int idx)
{
    ll res = 0;
    while (idx > 0) {
        res = res + Fenwick_Tree[idx];
        idx = idx - (idx & -idx);
    }
    return res;
}

void Update(int Idx, int Value)
{
    while (Idx <= MX_INPUT + 10) {
        Fenwick_Tree[Idx] = Fenwick_Tree[Idx] + Value;
        Idx = Idx + (Idx & -Idx);
    }
}

inline void DeletePrevCol(int r, int c)
{
    for (int i = 0; i < W; ++i) {
        int& val = arr[r + i][c];

        Update(val, -1);    
    }
}

inline void DeletePrevRow(int r, int c)
{
    // cout << "-------------r c " << r << " " << c<<endl;

    for (int j = 0; j < W; ++j) {
        int& val = arr[r][c + j];
        // cout << val << endl;

        Update(val, -1);
    }
}

inline void AddCurCol(int r, int c) 
{
    // cout << "-------------r c " << r << " " << c<<endl;
    for (int i = 0; i < W; ++i) {
        int& val = arr[r + i][c];

        // cout << val << endl;
        Update(val, 1);    
    }
}

inline void AddCurRow(int r, int c)
{
    // cout << "-------------r c " << r << " " << c<<endl;

    for (int j = 0; j < W; ++j) {
        int& val = arr[r][c + j];
        // cout << val << endl;

        Update(val, 1);
    }
}

inline bool InRange(int r)
{
    return (r + W - 1 < M);
}

inline int bsearch()
{
    int lo = 1;
    int hi = MX_INPUT + 2;
    int best = MX_K;
    // cout << "bsearch" << endl;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int res = Sum(mid);
        if (res >= median) {
            best = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        // cout << lo << " " << hi << " " << res << " median : " << median<< endl;

    }
    return best;
}

int main()
{
    fastio;
    cout.tie(NULL);
    cin >> M >> N >> K >> W;
    for (int i = 0; i < M; ++i) {
        int a;
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
            arr[i][j] += 1;
            MX_INPUT = max(arr[i][j], MX_INPUT);
        }
    }

    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < W; ++j) {
            int& val = arr[i][j];
            // cnt[val]++;
            Update(val, 1);
        }
    }

    // for (int i = 1; i <= 10; ++i) {
    //     cout << Fenwick_Tree[i] << " ";
    // }
    // cout << endl << "Sum " << endl;
    // for (int i = 1; i <= 10; ++i) {
    //     cout << Sum(i) << " ";
    // }
    // cout << endl;

    median = (W*W + 1) / 2;
    int row = 0, col = 0;
    while (true) {
        
        // if (row == M - W && col == N - W) break;
        
        if (!InRange(row)) break;

        if (row != 0) {
            DeletePrevRow(row - 1, 0);
            AddCurRow(row + W - 1, 0);
        }
        // -> 탐색
        for (col = 0; col <= N - W; ++col) {
            if (col != 0) {   
                DeletePrevCol(row, col - 1);
                AddCurCol(row, col + W - 1);  
            }
            ans[row][col] = bsearch();
            // cout << row << " " << col << endl;
        }
        ++row;
        --col;
        if (!InRange(row)) break;
        
        DeletePrevRow(row - 1, N - W);
        AddCurRow(row + W - 1, N - W);
        
        // <- 탐색
        for (col = N - W; col >= 0; --col) {
            if (col != N - W) {
                DeletePrevCol(row, col + W);
                AddCurCol(row, col);
            }
            ans[row][col] = bsearch();
            // cout << row << " " << col << endl;
        }
        ++row;
        ++col;
    }

    // cout << endl << "Output" << endl;
    for (int i = 0; i <= M - W; ++i) {
        for (int j = 0; j <= N - W; ++j) {
            cout << ans[i][j] - 1 << " ";
        }
        cout << endl;
    }

    return 0;
}