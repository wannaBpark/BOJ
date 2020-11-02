#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
stack<char> s;
char A[101000];
int ans = 0;
int main()
{
	scanf("%s", &A);
	int size = strlen(A);
	for (int i = 0; i < size; i++) {
		if (A[i] == '(') {
			s.push('(');
		}
		else if (A[i] == ')') {
			if (A[i-1] == '(') {
				s.pop(),ans += s.size();
			}
			else {
				s.pop(), ++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
//int main()
//{
//	scanf("%s", &A);
//	int size = strlen(A);
//	int cntBar = 0,cntRaser = 0, mx = 0;
//	for (int i = 0; i < size-1; i++) {
//		if (A[i] == '(') {
//			if (A[i + 1] == '(') cntBar++,mx++;
//			else if(cntBar) cntRaser++;
//		}
//		else if (A[i] == ')') {
//			if (A[i - 1] == ')') {
//				printf("%d¹øÂ° %d\n", i, cntBar);
//
//				ans += ((cntRaser*cntBar)+1), cntBar--;
//			}
//		}
//		
//	}
//	printf("%d %d\n", ans,mx);
//	return 0;
//}