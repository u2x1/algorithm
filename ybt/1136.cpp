#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  char c;
  while ((c = getchar()) != EOF && c != '\n') {
    if (c == 'z' || c == 'Z') {
      c = c - 25;
    } else if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z')) {
      ++c;
    }
    putchar(c);
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
