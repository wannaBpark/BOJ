#include <map>
#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
char A[505][505];
char ans[250500];

vector<map<char, int>> v;

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K * K; ++i) {
		map<char, int> m;
		v.push_back(m);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf(" %c", &A[i][j]);
			char c = A[i][j];
			int idx = (i % K) * K + (j % K);
			map<char, int>& m = v[idx];
			m[c] += 1;
		}
	}
	for (int i = 0; i < K * K; ++i) {
		auto& m = v[i];
		int cnt = 0;
		char candidate;
		for (auto it : m) {
			if (cnt < it.second) {
				cnt = it.second;
				candidate = it.first;
			}
		}
		ans[i] = candidate;
	}

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int idx = (i % K) * K + j % K;
			if (ans[idx] != A[i][j]) {
				++sum;
				A[i][j] = ans[idx];
			}
		}
	}
	printf("%d\n", sum);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%c", A[i][j]);
		}
		puts("");
	}
	return 0;
}	
