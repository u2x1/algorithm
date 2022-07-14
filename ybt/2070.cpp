#include <cstdio>

int main() {
  char a, b, c;
  scanf("%c%c%c", &a, &b, &c);
  if (c == '0') {
    if (b == '0'){
      printf("%c", a);
    } else {
      printf("%c%c", b, a);
    }
  } else {
    printf("%c%c%c", c, b, a);
  }
  return 0;
}

