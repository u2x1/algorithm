#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  int occur[26];
  memset(occur, 0, sizeof(occur));
  char c;
  while ((c=getchar()) != EOF && c != '\n') {
    ++occur[c-'a'];
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int max = 0; int min = 100;
  for(int i = 0; i < 26; ++i) {
    if (occur[i] == 0) { continue; }
    if (max < occur[i]) { max = occur[i]; }
    if (min > occur[i]) { min = occur[i]; }
  }
  int diff = max - min;
  if (diff < 2) { printf("No Answer\n0"); return 0; }
  for (int i = 2; i < diff; ++i) {
    if (diff % i == 0) { printf("No Answer\n0"); return 0; }
  }
  printf("Lucky Word\n%d", diff);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
