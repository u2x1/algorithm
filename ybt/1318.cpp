#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
int n;
int arr[10001];

void f(const int x, const int pos) {
//  printf("x: %d pos: %d\n", x, pos);
  if (x == 0) {
    if (pos == 2) { return; }
    printf("%d=%d", n, arr[1]);
    for(int i = 2; i < pos; ++i) {
      printf("+%d", arr[i]);
    }
    putchar('\n');
    return;
  }
  if (x < 0) { return; }
  for(int i = arr[pos-1]; i <= x; ++i) {
    if (x - i >= 0) { arr[pos] = i; f(x-i, pos+1); }
    else { return; }
  }
}

int main() {
  scanf("%d", &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  arr[0] = 1;
  f(n, 1);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
