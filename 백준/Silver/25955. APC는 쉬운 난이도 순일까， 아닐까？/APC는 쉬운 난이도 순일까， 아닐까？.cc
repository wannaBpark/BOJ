#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<char, int>> v1;
vector<pair<char, int>> v2;
int N;
int tier[1000];
int main()
{
	scanf("%d", &N);
	char c;
	int num;
	for (int i = 0; i < N; ++i) {
		scanf(" %c%d", &c, &num);
		v1.push_back({ c, num });
		v2.push_back({ c, num });
	}

	tier['B'] = 1, tier['S'] = 2, tier['G'] = 3, tier['P'] = 4, tier['D'] = 5;
	
	bool isSwap = false;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			char c1 = v1[i].first, c2 = v1[j].first;
			int r1 = v1[i].second, r2 = v1[j].second;
			if ((tier[c1] > tier[c2] || (c1 == c2 && r1 < r2))) {
				swap(v1[i], v1[j]);
				isSwap = true;
			}
		}
	}
	isSwap == true ? puts("KO") : puts("OK");

	for (int i = 0; i < N; ++i) {
		if (!(v2[i].first == v1[i].first && v2[i].second == v1[i].second)) {
			printf("%c%d ", v1[i].first, v1[i].second);
		}
	}
	
	return 0;
}