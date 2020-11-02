#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int N,ans=0;
int main()
{
	scanf("%d", &N);
	for(int j=0; j<N; j++) {
		stack<char> s;
		char A[101000];
		scanf("%s", &A);
		int length = strlen(A); 
		//처음에 strlen(A)를 ↓반복문 바로 넣었는데, 이때 호출되는 횟수가 문제였나보다
		for (int i = 0; i < length; i++) {
			if (!s.empty() && s.top() == A[i]) s.pop();
			else s.push(A[i]);
		}
		if (s.empty()) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
//({)
// ({})
// {()}
//(()){{}}