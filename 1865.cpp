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
	
	// 벡터안써서 그런가, 2*M+W는 너무 커서그런가
	scanf("%d", &TC);
	while (TC--) {
		bool flag = false;
		scanf("%d%d%d", &N, &M, &W);
		for (i = 1; i <= N; i++) //cost 배열 INF로 초기화
			dist[i] = INF;
		dist[1] = 0; //출발점에서 출발점으로 가는건 0
		for (i = 0; i < M; i++) { 
			scanf("%d%d%d", &s, &e, &t);
			V[i] = { s,e,t }; //도로 값 저장
		}
		for (i =M; i < M + W; i++) { //웜홀값 저장 
			scanf("%d%d%d", &s, &e, &t);
			V[i] = { s,e,-t };
		}
		for (j = 1; j <= N; j++) { //정점 개수만큼 돌아야 *음수*사이클 체크
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
			//N번 돈다는 소리= 정점을 두번 본다 = 중간에 음수사이클 있다
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