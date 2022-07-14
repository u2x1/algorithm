#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  int cnt[30]; char exist[30]; int pos = 0;
  memset(cnt, 0, sizeof(cnt));
  char c; int i;
  while ((c = getchar()) != EOF) {
    i = c - 'a';
    if (cnt[i] == 0) {
      exist[pos++] = c;
    }
    ++cnt[i];
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  for (int j = 0; j < pos; ++j) {
    if (cnt[exist[j]-'a'] == 1) {
      printf("%c", exist[j]);
      return 0;
    }
  }
  printf("no");

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
