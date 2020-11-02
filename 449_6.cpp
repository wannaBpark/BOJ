#include <cstdio>
int Fac[7];
//int Com(int n, int r)
//{
//
//}
int main()
{
	//freopen("input.txt", "r", stdin);
	Fac[1] = 1;
	for (int i = 2; i <= 6; i++) {
		Fac[i] = Fac[i - 1] * i;
	}
	
	return 0;
}