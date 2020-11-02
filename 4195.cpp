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
////�й� :201921094
////�̸� :����
////��¥ :2019.06.07
////���α׷� ���� :�ؽ�Ʈ ������ ù��° �ٿ��� �ð� ������ ����, �ι�° �ٺ��ʹ� �ð� ������ ��, ��, ����
////������ ����Ǿ� �ִ�. (input.txt ����) �� ������ ������ �������� �Ҵ�� time_t ����ü �迭��
////������ ��, ���̳ʸ� ���Ϸ� �����ϴ� ���α׷��� �ۼ��Ѵ�
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
//	/*input.txt ����*/
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
//	/*input.txt ���� �о� ����ü�� ����*/
//
//	fp = fopen("input.txt", "r");
//	int buffer, index = 0, arr_index = 0;
//	Time *t_data = (Time*)malloc(sizeof(Time)*n);
//	while (fscanf(fp, "%d", &buffer) != EOF) {
//		index++;
//		if (index == 1)//������ �о������ ��ŵ�� �� �ֵ���
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
//	/*����ü���� �о� bin���Ͽ� ����*/
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
//}r; //result r; ��������
//// vertical = 0, horizontal = 1, oblique = 2
//LINE connect(POINT p1, POINT p2)
//{
//	LINE line;
//	return line = { p1.x, p1.y, p2.x, p2.y }; //point �ΰ� �޾��ְ� line�� ����, line ��ȯ
//}
//result func(LINE input) {
//	if (input.beg.x - input.end.x == 0) return r = vertical;
//	if (input.beg.y - input.end.y == 0) return r = horizontal;
//	else if (input.beg.x - input.end.x != 0 && input.beg.y - input.end.y != 0) return r = oblique;
//	//enum�� �Լ� ����. r�������� �ߴ��� ��ȯ
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
//		input = connect(p1, p2); //p1,p2�ְ� line ��ȯ�Ѱ� ����
//		r = func(input); //line �ְ� enum(result) ��ȯ�Ѱ� ����
//		switch (r) {
//		case 0: printf("The line connecting the points is vertical\n"); break;
//		case 1: printf("The line connecting the points is horizontal\n"); break;
//		case 2: printf("The line connecting the points is oblique\n"); break;
//
//		}
//		getchar(); //����ó��
//		printf(TRY);
//		scanf("%c", &tt);
//		switch (tt) {
//		case 'y':  break;
//		case 'q': bye = 0; printf("Bye\n"); break;
//		}
//	}
//	return 0;
//}
