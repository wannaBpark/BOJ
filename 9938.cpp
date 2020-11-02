#include <cstdio>
#define MAX 300000
#define LADICA printf("LADICA\n");
#define SMECE printf("SMECE\n");
//공책 그림 참고, 비어있는 것이 parent이다.
int N, L;
int p[MAX] = { 0, }, chk[MAX] = { 0, },a, b;
int find(int a)
{
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b)
{
	a = find(a); b = find(b);
	p[a] = b;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &L);
	for (int i = 1; i <= L; i++) {
		p[i] = i;
	}
	while (N--) {
		scanf("%d%d", &a, &b);
		if (!chk[a]) { //서랍 Ai가 비어있다면.
			chk[a] = 1;
			merge(a, b);
			LADICA
		}
		else if (!chk[b]) {
			chk[b] = 1;
			merge(b, a); //2번룰 다음은 3번룰이므로 merge(b,a);
			LADICA
		}
		else if (!chk[find(a)]) { //3번룰 다음은 4번룰
			chk[find(a)] = 1;
			merge(a, b);
			LADICA
		}
		else if (!chk[find(b)]) { //4번룰 다음은 없다. merge 순서 상관없
			chk[find(b)] = 1;
			merge(a, b);
			LADICA
		}
		else {
			SMECE
		}
	}

}
//원래코드 : 단순구현, 메모이제이션도 없음


//int find(int a)
//{
//	if (!p[a]) {
//		return 1;
//	}
//	else if (p[a] == -1) {
//		return 0;
//	}
//	return find(p[a]);
//
//	//int r = uni(p[a]);
//	//if (!r) r = uni(b);
//	//else {
//	//	p[a] = b;
//	//	return 1; //옮기는데 성공했으면 거기에 배치.
//	//}
//	//if (!r) return 0;
//	//else {
//	//	p[b] = -1;
//	//	return 1;
//	//}
//}
//void update(int index, int fill)
//{
//	int nextIndex = p[index];
//	p[index] = fill;
//	if(nextIndex) update(nextIndex, -1);
//	//int par = a;
//	//if (!p[par]) {//옮길 수 있을 때 =
//	//	if (par) { // Ai로 배치됐는가?
//	//		p[par] = -1;
//	//		return 1;
//	//	}
//	//	else return 0; //Bi로 배치됐는가?
//	//}
//	//else if (p[par]) { //옮길 수 없을 때
//	//	int r = uni(p[par]);
//	//	if (!r) return 0;
//	//	else {
//	//		p[par] = -1;
//	//		return 1;
//	//	}
//	//}
//	//	//옮기기 불가능하면 return 0
//	////가능하면 return 1;
//}
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &N, &L);
//	
//	for (int i = 1; i <= N; i++) {
//		int r = 1;
//		scanf("%d%d", &A[i], &B[i]);
//		if (!p[A[i]]) p[A[i]] = B[i];
//		else if (!p[B[i]]) p[B[i]] = -1;
//		else if (p[A[i]] && p[B[i]]) {
//			r = find(A[i]);
//			if (r) update(A[i], B[i]);
//			else if (!r) {
//				r = find(B[i]);
//				if (r) update(B[i], -1);
//			}
//			printf("%d번째 : ", i);
//			for (int i = 1; i <= L; i++) {
//				printf("%d ", p[i]);
//			}
//		}
//		printf("\n");
//		r ? printf("LADICA\n") : printf("SMECE\n");
//	}
//	return 0;
//}