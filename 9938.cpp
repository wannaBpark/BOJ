#include <cstdio>
#define MAX 300000
#define LADICA printf("LADICA\n");
#define SMECE printf("SMECE\n");
//��å �׸� ����, ����ִ� ���� parent�̴�.
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
		if (!chk[a]) { //���� Ai�� ����ִٸ�.
			chk[a] = 1;
			merge(a, b);
			LADICA
		}
		else if (!chk[b]) {
			chk[b] = 1;
			merge(b, a); //2���� ������ 3�����̹Ƿ� merge(b,a);
			LADICA
		}
		else if (!chk[find(a)]) { //3���� ������ 4����
			chk[find(a)] = 1;
			merge(a, b);
			LADICA
		}
		else if (!chk[find(b)]) { //4���� ������ ����. merge ���� �����
			chk[find(b)] = 1;
			merge(a, b);
			LADICA
		}
		else {
			SMECE
		}
	}

}
//�����ڵ� : �ܼ�����, �޸������̼ǵ� ����


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
//	//	return 1; //�ű�µ� ���������� �ű⿡ ��ġ.
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
//	//if (!p[par]) {//�ű� �� ���� �� =
//	//	if (par) { // Ai�� ��ġ�ƴ°�?
//	//		p[par] = -1;
//	//		return 1;
//	//	}
//	//	else return 0; //Bi�� ��ġ�ƴ°�?
//	//}
//	//else if (p[par]) { //�ű� �� ���� ��
//	//	int r = uni(p[par]);
//	//	if (!r) return 0;
//	//	else {
//	//		p[par] = -1;
//	//		return 1;
//	//	}
//	//}
//	//	//�ű�� �Ұ����ϸ� return 0
//	////�����ϸ� return 1;
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
//			printf("%d��° : ", i);
//			for (int i = 1; i <= L; i++) {
//				printf("%d ", p[i]);
//			}
//		}
//		printf("\n");
//		r ? printf("LADICA\n") : printf("SMECE\n");
//	}
//	return 0;
//}