#include <cstdio>
#include <queue>
using namespace std;
int A, B, C;
int cnt[210];
int visited[800][800];
queue<pair<int, int> > q;
int main()
{
	scanf("%d%d%d", &A, &B, &C);
	visited[A][B] = true;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		int z = C - (x + y);
		q.pop();
		if (visited[x][y]) continue;
		if (x == 0) cnt[z]++;
		int nx, ny, nz;
		//printf("%d %d %d\n", x, y, z);
		//x->y
		if (x != 0 && y!=B) {
			if (y + x > B) {
				ny = B; nx = y + x - B;
				//printf("n-3 %d %d\n", nx, ny);
				if(!visited[nx][ny]) q.push({ nx,ny });
			}
			else {
				ny = y + x; nx = 0;
				//printf("n-2 %d %d\n", nx, ny);
				if (!visited[nx][ny])q.push({ nx,ny });
			}
		}
		//x->z
		if (x != 0 && z!=C) {
			if (z + x > C) {
				nz = C; nx = z + x - C; ny = C - (nx + nz);
				//printf("n-1 %d %d\n", nx, ny);
				if (!visited[nx][ny]) q.push({ nx,ny });
			}
			else {
				nz = z + x; nx = 0; ny = C - (nx + nz);
				//printf("n0 %d %d\n", nx, ny);
				if (!visited[nx][ny]) q.push({ nx,ny });
			}
		}
		//y->x
		if (y != 0 && x!=A) {
			if (x+y > A) {
				nx = A; ny = x + y - A;
				//printf("n1 %d %d\n", nx, ny);
				if (!visited[nx][ny]) q.push({ nx,ny });
			}
			else {
				nx = x+y; ny = 0; 
				//printf("n2 %d %d\n", nx, ny);
				if (!visited[nx][ny]) q.push({ nx,ny });
			}
		}
		//y->z
		if (y != 0 && z!=C) {
			if (z+ y  > C) {
				ny = z + y - C; 
				//printf("n3 %d %d\n", x, ny);
				if (!visited[nx][ny]) q.push({ x,ny });
			}
			else {
				ny = 0;
				//printf("n4 %d %d\n", x, ny);
				if (!visited[nx][ny]) q.push({ x, ny });
			}
		}
		//z->x
		if (z != 0 && x!=A) {
			if (x+z > A) {
				nx = A;
				//printf("n5 %d %d\n", nx, y);
				if (!visited[nx][y]) q.push({ nx,y });
			}
			else {
				nx = x+z;
				//printf("n6 %d %d\n", nx, y);
				if (!visited[nx][y]) q.push({ nx,y });
			}
		}
		//z->y
		if (z != 0 && y!=B) {
			if (y + z > B) {
				ny = B;
				//printf("n7 %d %d\n", x, ny);
				if (!visited[x][ny])q.push({ x,ny });
			}
			else {
				ny = y + z;
				//printf("n8 %d %d\n", x, ny);
				if (!visited[x][ny])q.push({ x,ny });
			}
		}		
		visited[x][y] = true;
	}
	for (int i = 0; i <= 200; i++) if (cnt[i]) printf("%d ", i);
	return 0;
}