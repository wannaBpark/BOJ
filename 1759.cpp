#include <cstdio>
#include <algorithm>
using namespace std;
char A[16], pick[16];
int L, C;
bool chk(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' ||
		c == 'o' || c == 'u') return 1; //모음 return 1
	else return 0; //자음 return 0
}
void backtracking(int index, int length,int consonant, int vowel)
{
	//printf("%d %d %d %d\n", index, length, consonant, vowel);
	if (length >= L) {
		/*int c = 0, v = 0;
		for (int i = 0; i < L; i++) {
			if (chk(pick[i])) v++;
			else c++;
		}*/
		if (consonant>=2 && vowel>=1) { //처음에 여집합 잘못설정했다가 틀림. 조건 잘 체크하자.
			for (int i = 0; i < L; i++) printf("%c", pick[i]);
			puts("");
		}
		return;
	}
	if (index>= C) return;
	for (int i = index+1; i < C; i++) {
		pick[length] = A[i];
		if (chk(A[i])) backtracking(i, length + 1, consonant, vowel + 1);
		else backtracking(i, length + 1, consonant+1, vowel);
	}
	return;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &L, &C);
	for (int i = 0; i < C; i++) scanf(" %c", &A[i]);
	sort(A, A + C);
	backtracking(-1, 0, 0, 0);
	return 0;
}