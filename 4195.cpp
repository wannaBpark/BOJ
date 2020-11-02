#include <cstdio>
#include <string>
#include <map>
using namespace std;
int F, TC;
int p[200000], Rank[2000000] = { 0, }, Net[2000000];
int find(int a)
{
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
int uni(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return Net[a];
	if (Rank[a] == Rank[b]) {
		p[a] = b; ++Rank[b];
		return Net[b] += Net[a];
	}
	else if (Rank[a] < Rank[b]) {
		p[a] = b; ++Rank[b];
		return Net[b] += Net[a];
	}
	else {
		p[b] = a;
		return Net[a] += Net[b];
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &F);
		for (int i = 1; i <= F * 2 + 1; i++) { p[i] = i; Net[i] = 1; }
		map<string, int> _m;
		int friendCount = 1;
		char a[21], b[21];
		while (F--) {
			scanf("%s %s", a,b);
			if (!_m.count(a)) _m[a] = friendCount++;
			if (!_m.count(b)) _m[b] = friendCount++;
			printf("%d\n", uni(_m[a], _m[b]));
		}
	}
	return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//int main()
//{
//	FILE* fp = fopen("input.txt", "rt");
//	
//	int index = 0, length;
//	fscanf(fp, "%d", &length);
//	double *x = (double *)malloc(sizeof(double)*length);
//	double *y = (double *)malloc(sizeof(double)*length);
//	double answer = 0;
//
//	for (index = 0; index<length; index++) {
//		fscanf(fp, "%lf %lf", &x[index], &y[index]);
//	}
//	for (index = 0; index < length - 1; index++) {
//		answer += (x[index] + x[index + 1]) * (y[index + 1] - y[index]);
//	}
//	answer = answer / 2.0;
//	printf("%lf\n", fabs(answer));
//
//	free(x); free(y);
//	fclose(fp);
//	return 0;
//}
////학번 :201921094
////이름 :김현
////날짜 :2019.06.07
////프로그램 설명 :텍스트 파일의 첫번째 줄에는 시간 정보의 개수, 두번째 줄부터는 시간 정보가 시, 분, 초의
////순서로 저장되어 있다. (input.txt 참고) 이 파일의 내용을 동적으로 할당된 time_t 구조체 배열에
////저장한 후, 바이너리 파일로 저장하는 프로그램을 작성한다
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//typedef struct time {
//	int second;
//	int minute;
//	int hour;
//}Time;
//
//int main()
//{
//
//	/*input.txt 생성*/
//
//	int n;
//	FILE *fpr = fopen("input.dat", "rb");
//	FILE *fpw = fopen("output.txt", "rt");
//	printf("Enter the number of data: ");
//	scanf("%d", &n);
//
//	srand(time(NULL));
//
//	fprintf(fp, "%d\n", n);
//
//	for (int i = 0; i < n; i++) {
//		fprintf(fp, "%d %d %d\n", rand() % 24, rand() % 60, rand() % 60);
//	}
//
//	fclose(fp);
//
//	/*input.txt 에서 읽어 구조체에 저장*/
//
//	fp = fopen("input.txt", "r");
//	int buffer, index = 0, arr_index = 0;
//	Time *t_data = (Time*)malloc(sizeof(Time)*n);
//	while (fscanf(fp, "%d", &buffer) != EOF) {
//		index++;
//		if (index == 1)//갯수를 읽어왔을때 스킵할 수 있도록
//			continue;
//
//		switch (index % 3) {
//		case 2://hour
//			t_data[arr_index].hour = buffer;
//			break;
//
//		case 0://minuite
//			t_data[arr_index].minute = buffer;
//			break;
//
//		case 1://second
//			t_data[arr_index].second = buffer;
//			arr_index++;
//			break;
//		}
//	}
//	fclose(fp);
//
//	/*구조체에서 읽어 bin파일에 저장*/
//
//	fp = fopen("output.txt", "rt");
//	fprintf(fp, "%d\n", n);
//	int i;
//	for (i = 0; i < n; i++) {
//		fprintf(fp, "%d %d %d", t_data[i].hour, t_data[i].minute, t_data[i].second);
//	}
//
//	fclose(fp);
//	int buffer2;
//	Time* t_data2;
//	fp = fopen("output.bin", "rb");
//	fread(&buffer2, sizeof(int), 1, fp);
//	t_data2 = (Time*)malloc(sizeof(Time)*buffer2);
//	fread(t_data2, sizeof(Time), buffer2, fp);
//	fclose(fp);
//	printf("%d\n", buffer2);
//	for (int i = 0; i < buffer2; i++) {
//		printf("%d %d %d\n", t_data2[i].hour, t_data2[i].minute, t_data2[i].second);
//	}
//
//
//	free(t_data2);
//	free(t_data);
//	fclose(fp);
//
//
//
//
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#define ENTER "Enter the coordinates of two points.\n"
//#define POINT1 "Point 1: "
//#define POINT2 "Point 2: " 
//#define TRY "Try Again? Y/y continues, other quits. "
//typedef struct { int x; int y; } POINT;            //
//typedef struct { POINT beg;    POINT end; } LINE;  //
//enum result {
//	vertical, horizontal, oblique
//}r; //result r; 변수선언
//// vertical = 0, horizontal = 1, oblique = 2
//LINE connect(POINT p1, POINT p2)
//{
//	LINE line;
//	return line = { p1.x, p1.y, p2.x, p2.y }; //point 두개 받아주고 line에 대입, line 반환
//}
//result func(LINE input) {
//	if (input.beg.x - input.end.x == 0) return r = vertical;
//	if (input.beg.y - input.end.y == 0) return r = horizontal;
//	else if (input.beg.x - input.end.x != 0 && input.beg.y - input.end.y != 0) return r = oblique;
//	//enum형 함수 선언. r변수선언 했던거 반환
//}
//int main()
//{
//	LINE input;
//	POINT p1; POINT p2;
//	char tt;
//	int bye = 1;
//	r = vertical;
//	while (bye) {
//		printf(ENTER);
//		printf(POINT1);
//		scanf("%d %d", &p1.x, &p1.y);
//
//		printf(POINT2);
//		scanf("%d %d", &p2.x, &p2.y);
//		input = connect(p1, p2); //p1,p2넣고 line 반환한거 대입
//		r = func(input); //line 넣고 enum(result) 반환한거 대입
//		switch (r) {
//		case 0: printf("The line connecting the points is vertical\n"); break;
//		case 1: printf("The line connecting the points is horizontal\n"); break;
//		case 2: printf("The line connecting the points is oblique\n"); break;
//
//		}
//		getchar(); //버퍼처리
//		printf(TRY);
//		scanf("%c", &tt);
//		switch (tt) {
//		case 'y':  break;
//		case 'q': bye = 0; printf("Bye\n"); break;
//		}
//	}
//	return 0;
//}
