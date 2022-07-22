#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

bool b[8], dl[15], dr[15];
int arr[8], rst[93], cnt;

void f(int pos) {
  if (pos == 8) {
    int tmp = 0;
    for(int i = 0; i<8; ++i) {
      tmp = tmp*10 + arr[i];
    }
    rst[++cnt] = tmp;
    return;
  }
  for(int i = 0; i < 8; ++i) {
    if (!b[i] && !dl[pos-i+7] && !dr[pos+i]) {
      arr[pos] = (i+1); b[i] = 1; dl[pos-i+7] = 1; dr[pos+i] = 1;
      f(pos+1);
      b[i] = 0; dl[pos-i+7] = 0; dr[pos+i] = 0;
    }
  }
}

int main() {
  f(0);

  int n;
  scanf("%d", &n);
  int x;
  for(int i = 0; i < n && scanf("%d", &x) == 1; ++i) {
    printf("%d\n", rst[x]);
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////


#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
