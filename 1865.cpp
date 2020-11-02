#include <cstdio>
int TC, N, M, W;
int dist[501];
const int INF = 25000000;
struct Edge {
	int from;
	int to;
	int time;
}V[2701];
int main()
{
	//freopen("input.txt", "r", stdin);
	int s, e, t,j,update=0,i;
	
	// ���;ȽἭ �׷���, 2*M+W�� �ʹ� Ŀ���׷���
	scanf("%d", &TC);
	while (TC--) {
		bool flag = false;
		scanf("%d%d%d", &N, &M, &W);
		for (i = 1; i <= N; i++) //cost �迭 INF�� �ʱ�ȭ
			dist[i] = INF;
		dist[1] = 0; //��������� ��������� ���°� 0
		for (i = 0; i < M; i++) { 
			scanf("%d%d%d", &s, &e, &t);
			V[i] = { s,e,t }; //���� �� ����
		}
		for (i =M; i < M + W; i++) { //��Ȧ�� ���� 
			scanf("%d%d%d", &s, &e, &t);
			V[i] = { s,e,-t };
		}
		for (j = 1; j <= N; j++) { //���� ������ŭ ���ƾ� *����*����Ŭ üũ
			update = 0;
			for (int i = 0; i < M; i++) {
				if (dist[V[i].to] > dist[V[i].from] + V[i].time) {
					dist[V[i].to] = dist[V[i].from] + V[i].time;
					update = 1;
				}
				else if(dist[V[i].from] > dist[V[i].to]+V[i].time){
					dist[V[i].from] = dist[V[i].to] + V[i].time;
					update = 1;
				}
			}
			for (int i = M; i < M+W; i++) {
				if (dist[V[i].to] > dist[V[i].from] + V[i].time) {
					dist[V[i].to] = dist[V[i].from] + V[i].time;
					update = 1;
				}
			}
			//N�� ���ٴ� �Ҹ�= ������ �ι� ���� = �߰��� ��������Ŭ �ִ�
			/*for (int i = 1; i <= N; i++) {
				printf("%d ", dist[i]);
			} printf("%d\n\n",j);*/
			if (update && j == N) flag = true;

			if (!update) break; //
			update = 0;
		}
		printf(flag ? "YES\n" : "NO\n");
	}

	return 0;
}