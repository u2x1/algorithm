#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  char s[101];
  scanf("%s", s);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  char rst[101];
  int len = strlen(s);
  for(int i = 0; i < len-1; ++i) {
    rst[i] = s[i] + s[i+1];
  }
  rst[len-1] = s[0] + s[len-1];
  rst[len] = '\0';
  printf("%s", rst);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
