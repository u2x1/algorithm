#include <cstdio>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 1e5;
int arr[maxN];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  cfor(i, 0, n, 1) { scanf("%d", arr+i); }
  return 0;
}
