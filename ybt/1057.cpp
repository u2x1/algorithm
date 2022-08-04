#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int a, b; char op;
  scanf("%d%d %c", &a, &b, &op);
  if (op == '/' && b == 0) { printf("Divided by zero!"); return 0; }
  int ans;
  switch(op) {
    case '+':
      ans = a+b;
      break;
    case '-':
      ans = a-b;
      break;
    case '*':
      ans = a*b;
      break;
    case '/':
      ans = a/b;
      break;
    default:
      printf("Invalid operator!");
      return 0;
      break;
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", ans);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
