#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int pells[1000010];
int pos = 2;
int pell(int x) {
  if (pells[x]) { return pells[x]; }
  for (; pos<=x; ++pos) {
    pells[pos] = (2*pells[pos-1] + pells[pos-2])%32767;
  }
  return pells[x];
}

int main() {
  int n;
  scanf("%d", &n);
  pells[1]=1; pells[2]=2;
  int x;
  for (int i=0; i<n && scanf("%d", &x) == 1; ++i) {
    printf("%d\n", pell(x));
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
