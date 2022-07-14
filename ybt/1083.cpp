#include <cstdio>

int main() {
  int a, b, ret = 1;
  scanf("%d%d", &a, &b);
  a %= 7;
  for (int i = 0; i < b; ++i) {
    ret *= a; ret %= 7;
  }
  switch (ret) {
    case 1:
      printf("Monday");
      break;
    case 2:
      printf("Tuesday");
      break;
    case 3:
      printf("Wednesday");
      break;
    case 4:
      printf("Thursday");
      break;
    case 5:
      printf("Friday");
      break;
    case 6:
      printf("Saturday");
      break;
    case 0:
      printf("Sunday");
      break;
  }
  return 0;
}
