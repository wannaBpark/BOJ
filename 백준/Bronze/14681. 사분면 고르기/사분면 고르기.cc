#include <stdio.h>
#define jungsoo %d 
int main()
{
	int x, y;
	scanf("%d\n%d", &x, &y);
	if (x > 0) {
		if (y > 0) {
			printf("1");
		} else if (y < 0) {
			printf("4");
		}
	}else if (x < 0) {
		if (y > 0) {
			puts("2");
		}
		else if (y < 0) {
			puts("3");
		}
	}
	return 0;
}