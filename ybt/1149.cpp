#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  char s[501];
  int maxLen = 0, cLen;
  char maxWord[501];
  while (scanf("%s", s) != EOF) {
    cLen = strlen(s);
    if (s[cLen - 1] == '.') { s[--cLen] = '\0'; break; }
    if (maxLen < cLen) { strcpy(maxWord, s); maxLen = cLen; }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  if (maxLen < cLen) { strcpy(maxWord, s); maxLen = cLen; }
  printf("%s", maxWord);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
