#include <stdio.h>
#define msg_input "\nEnter 1 ~ 100 integers ranged 0 ~ 200: "
#define msg_layout "\nNumber\tFrequency\n"
#define msg_continue "\nType C for continue or Q for quit: "
#define msg_end "Program terminating. Bye!\n"
#define msg_err "Invalid input. Try again.\n"

int main() {
	
	int i = 0;
	char flag_continue = 'C';
	bool err = 0;
	while (flag_continue == 'C') {
		//초기화
		int input[101] = { 0, };
		int num_flag[201] = { 0, };
		i = 0;
		// input
		printf(msg_input);
		do {
			scanf("%d", &input[i]);
			if (input[i] < 1 || input[i]> 200)
				err = 1;
			num_flag[input[i]] += 1;
			i++;
		} while (getc(stdin) == ' ');
		// output
		if (err == 1) {
			err = 0;
			printf(msg_err);
			continue;
		}
		else {
			printf(msg_layout);

			for (int j = 0; j <= 200; j++) {
				if (num_flag[j]>0) {
					printf("%d\t%d\n", j, num_flag[j]);
				}
			}
		}
		//재실행 여부
		printf(msg_continue);
		scanf("%c", &flag_continue);
		//종료
		if (flag_continue == 'Q') {
			printf(msg_end);
			break;
		}
	}
	return 0;
}
//#include <iostream>
//#include <queue>
//#include <string>
//using namespace std;
//queue<int> q;
//int N,M;
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &N);
//	for (int i = 1; i <= N - 1; i++)
//		scanf("%d%d%d");
//	scanf("%d", &M);
//	for (int i = 1; i <= M; i++) {
//		scanf("%d%d%d",)
//	}
//}