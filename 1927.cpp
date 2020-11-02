#include <cstdio>
#define MAX_N 100002
#define MIN(a,b) (a<b) ? 1 : 0
#define MAX(a,b) (a>b) ? 1 : 0
#define swap(a,b) {auto tmp = a; a=b; b=tmp;}
int heap[MAX_N];
int size=0;
//처음엔 전체탐색-> 그럴 필요 x 그부분의 자식과 부모만 봐주면 됌.
void push(int num)
{
	heap[++size] = num;
	int child = size;
	int parent = size / 2; //입력받은 부분의 힙만 살펴보면 된다. 전체탐색X
	while (child > 1 && MIN(heap[child], heap[parent])) {
		swap(heap[child], heap[parent]);
		child = parent; parent /= 2;
	}
}
int pop()
{
	if (size==0) return 0;
	int output = heap[1];
	heap[1] = heap[size--];
	int parent = 1;
	int child = parent * 2;
	if (MIN(heap[child + 1], heap[child]) && child + 1 <= size)
		++child;
	while (child <= size && MIN(heap[child], heap[parent])) {
		swap(heap[child], heap[parent]);
		parent = child;
		child *= 2;
		if (MIN(heap[child+1], heap[child]) && child + 1 <= size)
			++child;
	}
	return output;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int N,input;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (input == 0) {
			printf("%d\n", pop());
		}
		else
			push(input);
	}
	return 0;
}
/*#define MAX_N 100002
#define MIN(a,b) (a>b) ? 1: 0
#define RIGHT(i) (i*2)
#define LEFT(i) (i*2+1)
int N,i=0,input;
int A[MAX_N] = { 0, };
using namespace std;
void heap(int s)
{
	//printf("s:%d\n", s);
	for (int i = 1; i<=s; i++) {
		if (MIN(A[i],A[RIGHT(i)]) && A[RIGHT(i)]!=0) swap(A[RIGHT(i)], A[i]);
		if (MIN(A[i], A[LEFT(i)]) && A[LEFT(i)] != 0) swap(A[LEFT(i)], A[i]);
	}
}	
void remove(int s)
{	
	s -= 2;
	heap(s);
}	
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	int s = 0;
	for (int i = 1; i <= N;i++) {
		scanf("%d", &input);
		//printf("%d\n", A[i-1]);
		switch (input) {
		case 0:
			printf("%d\n", A[1]);
			swap(A[1], A[s]);
			if (s >= 1) --s;
			heap(s);
			break;
		default: 
			++s;
			A[s] = input;
			heap(s);
			break;
		}
		for (int j = 1; j <= s;j++) {
			printf("%d ", A[j]);
		}
		puts("\n");
	}
	return 0;
}*/