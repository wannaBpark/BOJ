#include <cstdio>
#define swap(a,b) {auto tmp = a, a=b, b=tmp;}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int lcm(int a, int b) {
	return a*b / gcd(a, b);
}
int main()
{
	int a, b, c, d, l, g;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (b > d) { swap(b, d); swap(a, c); }
	l = lcm(b, d); g = gcd(b, d);
	a = l / b*a + l / d*c;
	b = l;
	printf("%d %d", a / gcd(a, b), b / gcd(a, b));
}