#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  char s1[9], s2[9];
  for(int i = 0; i < n && scanf("%s%s", s1, s2) != EOF; ++i) {
    if (s1[0] == s2[0]) { printf("Tie\n"); }
    else if (  (s1[0] == 'R' && s2[0] == 'S')
            || (s1[0] == 'S' && s2[0] == 'P')
            || (s1[0] == 'P' && s2[0] == 'R'))
    { printf("Player1\n"); }
    else { printf("Player2\n"); }
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
