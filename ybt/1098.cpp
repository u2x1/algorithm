#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  if (n%2==0) { printf("%d", n/2); return 0; }
  for (int i = 3; ; i += 2) {
    if (n%i == 0) { printf("%d", n/i); return 0; }
  }
  return 0;
}
