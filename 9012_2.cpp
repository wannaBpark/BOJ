#include <cstdio>
#include <string.h>
#include <stack>
using namespace std;
int N;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	while (N--) {
		char A[60]; stack<int> st;
		scanf("%s", &A);
		bool isAns = true;
		for (int i = 0; i < strlen(A); i++) {
			if (A[i] == '(') {
				st.push('(');
			}
			else {
				if (st.empty()) {
					isAns = false;
					break;
				}
				else {
					st.pop();
				}
			}
		}
		if (!st.empty()) isAns = false;
		if (isAns) puts("YES");
		else puts("NO");
	}
	return 0;
}