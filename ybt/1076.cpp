#include <cstdio>

int main() {
  int n, a, b;
  scanf("%d", &n);
  int lasting = 0, longest = 0;
  for (int i = 0; i < n && scanf("%d%d", &a, &b); ++i) {
    if (a >= 90 && a <= 140 && b <= 90 && b >= 60) {
      lasting += 1;
    } else {
      if (lasting > longest) { longest = lasting; }
      lasting = 0;
    }
  }
  if (lasting > longest) { longest = lasting; }
  printf("%d", longest);
  return 0;
}
