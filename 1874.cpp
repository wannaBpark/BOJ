#include <cstdio>
#include <stack>
#include<vector>
using namespace std;
int N;
int A[101000];
stack<int> s;
vector<char> v;
int main()
{
	bool isAns = true;
	scanf("%d", &N);
	int start = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		if (!s.empty()) {
			if (s.top() > A[i]) {
				isAns = false;
				break;
			}
			if (s.top() == A[i]) {
				s.pop(); v.emplace_back('-');
				continue;
			}
		}		
		for (start = start; start <= A[i]; start++) s.push(start),v.emplace_back('+');
		s.pop(); v.emplace_back('-');
	}
	if (!isAns) puts("NO");
	else {
		for (auto i : v) printf("%c\n", i);
	}
	return 0;
}