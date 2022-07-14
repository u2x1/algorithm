#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <string>
#include <cstdio>
#include <algorithm>

std::string words[51];

int main() {
  int cnt = 0;
  char cache[101];
  for (; scanf("%s", cache) != EOF; ++cnt) {
    words[cnt] = cache;
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::sort(words, words+cnt);
  printf("%s\n", words[0].c_str());
  for(int i=1; i<cnt; ++i) {
    if(words[i] != words[i-1]) {
      printf("%s\n", words[i].c_str());
    }
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
