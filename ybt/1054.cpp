#include <cstdio>

void sort(int *a, int *b, int *c) {
  int buffer;
  if (*a < *b) { buffer = *a; *a = *b; *b = buffer; }
  if (*b < *c) { buffer = *b; *b = *c; *c = buffer; }
  if (*a < *b) { buffer = *a; *a = *b; *b = buffer; }
}

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  sort(&a, &b, &c);
  if (b+c > a && a-b < c && b-c < a) {
    printf("yes");
  } else { printf("no"); }
  return 0;
}
