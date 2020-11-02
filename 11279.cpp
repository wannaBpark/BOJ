#include <cstdio>
#define MAX_N 100002
#define MIN(a,b) (a<b) ? 1 : 0
#define MAX(a,b) (a>b) ? 1 : 0
#define swap(a,b) {auto tmp = a; a=b; b=tmp;}
int heap[MAX_N];
int size = 0;
//ó���� ��üŽ��-> �׷� �ʿ� x �׺κ��� �ڽİ� �θ� ���ָ� ��.
void push(int num)
{
	heap[++size] = num;
	int child = size;
	int parent = size / 2; //�Է¹��� �κ��� ���� ���캸�� �ȴ�. ��üŽ��X
	while (child > 1 && MIN(heap[parent], heap[child])) {
		swap(heap[child], heap[parent]);
		child = parent; parent /= 2;
	}
}
int pop()
{
	if (size == 0) return 0;
	int output = heap[1];
	heap[1] = heap[size--];
	int parent = 1;
	int child = parent * 2;
	if (MAX(heap[child + 1], heap[child]) && child + 1 <= size)
		++child;
	while (child <= size && MIN(heap[parent], heap[child])) {
		swap(heap[child], heap[parent]);
		parent = child;
		child *= 2;
		if (MAX(heap[child + 1], heap[child]) && child + 1 <= size)
			++child;
	}
	return output;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int N, input;
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