#include <cstdio>
#include <algorithm>
using namespace std;
int N,queen[17],ans=0; //queen[1] =1 1�� 1���� queen����.
bool isPromising(int length)
{
	for (int i = 0; i < length; i++) {
		if (queen[i] == queen[length] || 
			abs(length - i) == abs(queen[length]- queen[i]))
			return false;
	}
	return true;
}
void back(int length)
{
	if (length == N) {
		ans++; return;
	}
	for (int i = 0; i < N; i++) {
		queen[length] = i;
		if (isPromising(length)) { //��������� length �Ѱ��� = ���� ����Ž��������
			back(length + 1);
		}
	}
	return;
	
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	back(0);
	printf("%d\n", ans);
	return 0;
}