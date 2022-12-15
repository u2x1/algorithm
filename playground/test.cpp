#include <stdio.h>

const int maxN = 1e5;
long long arr[maxN];

long long fac(int n) {
	static int len = 1;
	if (n <= len) { return arr[n]; }
  arr[n] = n * fac(n-1);
	len = n;
	return arr[n];
}

int main() {
	arr[1] = 1;
	for(int i = 1; i < 10; ++i) {
		printf("fac(%d)=%lld\n", i, fac(i));
	}
	return 0;
}
