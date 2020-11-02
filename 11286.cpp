#include <iostream>
#include <queue>
using namespace std;
struct q_ {
	int first;
	int second;
};
bool operator<(q_ i, q_ j) {
	if (i.first == j.first)
		return i.second < j.second;
	return i.first < j.first;
}
priority_queue<q_> pq;
int main()
{
	freopen("input.txt", "r", stdin);
	int N, input;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (input == 0) {
			if (pq.empty()) printf("0\n");
			else {
				printf("%d\n", -pq.top().second);
				pq.pop();
			}
		}
		else pq.push({ -abs(input), -input });
	}
	return 0;
}
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int N, input;
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &input);
//		if (input == 0) {
//			if (pq.empty()) printf("0\n");
//			else {
//				printf("%d\n", -pq.top().second);
//				pq.pop();
//			}
//		}
//		else pq.push({ -abs(input), -input });
//	}
//	return 0;
//}
//#include <cstdio>
//#include <math.h>
//#define MAX_N 100002
//#define MIN(a,b) (a<b) ? a : b
//#define MAX(a,b) (a>b) ? 1 : 0
//#define swap(a,b) {auto tmp = a; a=b; b=tmp;}
//int heap[MAX_N];
//int size = 0;
////처음엔 전체탐색-> 그럴 필요 x 그부분의 자식과 부모만 봐주면 됌.
//void push(int num)
//{
//	heap[++size] = num;
//	int child = size;
//	int parent = size / 2; //입력받은 부분의 힙만 살펴보면 된다. 전체탐색X
//	while (child > 1 && abs(heap[child])<= abs(heap[parent])) {
//		if(abs(heap[child]) < abs(heap[parent]))
//			swap(heap[child], heap[parent] );
//		if(-heap[child] == heap[parent] && heap[child] < heap[parent]) {
//			swap(heap[child], heap[parent]);
//		}
//		
//		child = parent; parent /= 2;
//	}
//}
//int pop()
//{
//	if (size == 0) return 0;
//	int output = heap[1];
//	heap[1] = heap[size--];
//	int parent = 1;
//	int child = parent * 2;
//	if (-heap[child + 1] == -heap[child] && child + 1 <= size)
//		child = (heap[child + 1] < heap[child]) ? child + 1 : child;
//	else if (abs(heap[child + 1])< abs(heap[child]) && child + 1 <= size)
//		++child;
//	while (child <= size && !(abs(heap[child]) > abs(heap[parent]) ) ) {
//
//		if (abs(heap[child]) < abs(heap[parent]))
//			swap(heap[child], heap[parent]);
//		if (-heap[child] == heap[parent] && heap[child] < heap[parent]) {
//			swap(heap[child], heap[parent]);
//		}
//		parent = child;
//		child *= 2;
//		if (-heap[child + 1] == -heap[child] && child + 1 <= size)
//			child = (heap[child + 1] < heap[child]) ? child + 1 : child;
//		else if (abs(heap[child + 1])< abs(heap[child]) && child + 1 <= size)
//			++child;
//	}
//	return output;
//}
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int N, input;
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &input);
//		if (input == 0) {
//			printf("%d\n", pop());
//		}
//		else
//			push(input);
//	}
//	return 0;
//}