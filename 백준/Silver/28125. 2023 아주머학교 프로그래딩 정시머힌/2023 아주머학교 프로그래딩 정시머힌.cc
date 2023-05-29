#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char from[] = "acijnotvw";
char to[] = "@[!;^07";
char A[500];
char ans[500];
int length = 0;
bool chkW(int i)
{
	if (A[i] == '\\' && A[i + 1] == '\\' && A[i + 2] == 39) {
		return true;
	}
	return false;
}
bool chkV(int i)
{
	if (A[i] == '\\' && A[i + 1] == 39) {
		return true;
	}
	return false;
}
void translate()
{
	int cnt = 0;
	int cnt_not = 0;
	int idx = 0;
	int length = strlen(A);
	for (int i = 0; i < length; i++) {
		bool isFind = false;
		//printf("%c ", A[i]);
		//printf("%d\n", i);
		for (int j = 0; j <= 6; ++j) {
			if (A[i] == to[j]) {
				ans[idx++] = from[j];
				cnt++;
				isFind = true;
				break;
			}
		}
		if (isFind == true) continue;


		if (chkV(i) == true) {
			ans[idx++] = 'v';
			i += 1;
			cnt++;
		} else if (chkW(i) == true) {
			ans[idx++] = 'w';
			i += 2;
			cnt++;
		} else {
			ans[idx++] = A[i];
			cnt_not++;
		}
	}
	
	ans[idx] = '\0';
	length = strlen(ans);
	if (cnt * 2 >= length) {
		printf("I don\'t understand\n");
		return;
	}
	printf("%s\n", ans);
}

int main()
{
	int N;
	scanf("%d", &N);
	while (N--) {
		scanf("%s", A);
		translate();
	}

	return 0;
}