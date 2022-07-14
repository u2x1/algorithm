#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  char raw[51];
  char c;
  const int diff = 'a' - 'A';
  int i = 0;
  for (; ((c = getchar()) != EOF) && c != '\n'; ++i) {
    if ((c >= 'x' && c <= 'z') || (c >= 'X' && c <= 'Z')) {
      c -= 23;
    } else if ((c >= 'a' && c < 'x') || (c >= 'A' && c <= 'X')) {
      c += 3;
    }
    if (c >= 'a') { c -= diff; }
    else { c += diff; }
    raw[i] = c;
  }
  raw[i] = '\0';

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  for(--i; i != -1; --i) {
    putchar(raw[i]);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
