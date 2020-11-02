#include <cstdio>
#include<cstring>
int A[100];
int B[10] = { 0,11,111,1111,11111,111111,1111111,11111111,111111111,1000000000 };
int main()
{
	int a,ans=0,jari=1,x,index=  0;
	scanf("%d", &a);
	for (int i = 0; i < 9; i++) {
		if (a >= B[i] && a < B[i + 1]) {
			printf("%d", i+1);
			return 0;
		}
	}/*
	if (a>=0 && a<=10) {
		puts("1"); return 0;
	}
	int tmp = 1;
	while(a>=tmp){
		tmp = tmp * 10 + 1;
		jari++;
	}
	printf("%d", jari);*/
	/*
	while (a != 0) {
		ans++;
		x = a % 10;
		A[index++] = x;
		a /= 10;
	}
	bool isMax = true;
	if (A[index - 1] == 1) {
		for (int i = index - 2; i >= 0; i--) {
			if (!(A[i] >= 1)) isMax = false;
		}
	}
	isMax ? printf("%d", ans) : printf("%d", ans-1);*/
	return 0;
}