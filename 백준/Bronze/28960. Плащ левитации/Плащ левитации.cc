#include <stdio.h>
#include <algorithm>
using namespace std;

int h, l, a,b;
int main()
{
	scanf("%d%d%d%d", &h, &l, &a, &b);
    if ( h*2 >= a && l >= b){
        puts("YES");
        return 0;
    }
    if ( h*2 >= b && l >= a){
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}