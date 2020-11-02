#include <cstdio>
int s1, s2,i,a,b;
bool spl = true, test = true;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &s1, &s2);
	for (i = 0; i < s1; i++) {
		scanf("%d%d", &a, &b);
		if (a != b) {
			spl = false; break;
		}
	}
	if (s2 != 0) {
		for (i = 0; i < s2; i++) {
			scanf("%d%d", &a, &b);
			if (a != b) {
				test = false; break;
			}
		}
	}
	if ((s2 == 0 && spl) || (s2!=0 && spl && test)) puts("Accepted");
	else if ((s2 != 0 && !spl) || (s2==0 && !spl)) puts("Wrong Answer");
	else if (s2 != 0 && spl && !test) puts("Why Wrong!!!");
	return 0;
}