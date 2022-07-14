#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int cnt[26];

int main() {
  char t;
  while((t=getchar()) != EOF && t <= 'z' && t >= 'a') {
    ++cnt[t-'a'];
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int maxCnt=-1, id;
  for(int i = 0; i<26; ++i) {
    if(cnt[i] > maxCnt) {
      maxCnt = cnt[i];
      id = i;
    }
  }
  printf("%c %d", id+'a', maxCnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
