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
		//ó���� strlen(A)�� ��ݺ��� �ٷ� �־��µ�, �̶� ȣ��Ǵ� Ƚ���� ������������
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