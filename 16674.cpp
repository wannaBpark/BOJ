#include <cstdio>
#include<cstring>
int A[100];
int r[4] = { 2,0,1,8 };
int main()
{
	int a,namu;
	scanf("%d", &a);
	while (a != 0) {
		namu = a % 10;
		A[namu]++;
		a /= 10;
	}
	int x; bool isRelated = true;
	for (int i = 0; i <= 9; i++) {
		x = A[i];
		if ((i != 2 && i!=0 && i!= 1 && i!=8) && x) isRelated = false;
	}
	if (!isRelated) {
		puts("0");
		return 0;
	}
	if (!(A[2] && A[0] && A[8] && A[1])) {
		puts("1");
		return 0;
	}
	x = A[2]; bool isMook = true;
	for (int i = 1; i < 4; i++) {
		int tmp = r[i];
		if (x != A[tmp]) isMook = false;
	}
	isMook ? puts("8") : puts("2");
	return 0;
}