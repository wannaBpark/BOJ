#include <cstdio>
#include <stack>
#include<cstring>
using namespace std;
int T;
char str[51];
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		stack<char> s;
		scanf("%s", str);
		bool isAns = true;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == '(') {
				s.push('(');
			}
			else {
				if (s.empty()) {
					isAns = false;
					break;
				}
				else {
					s.pop();
				}
			}
		}
		if (!s.empty()) isAns = false;
		isAns ? puts("YES") : puts("NO");
	}
	return 0;
}