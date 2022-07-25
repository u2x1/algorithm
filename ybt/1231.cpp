#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  const int LEN = 500000;
  int n;
  scanf("%d", &n);
  char str[LEN]; int del;
  bool rm[LEN];
  int last[LEN], lastPos;
  while(n--) {
    last[0] = 0;
    lastPos = 0;
    memset(rm, 0, sizeof(rm));
    scanf("%s%d", str, &del);
    const int len = strlen(str),
              left = len - del;
    for(int i = 2; i < len && del != 0; ++i) {
      if (lastPos == -1) {
        last[++lastPos] = i-1;
        continue;
      }
      if (str[i-1] > str[last[lastPos]] && str[i-1] > str[i]) {
        rm[i-1] = 1; del--;
      } else if (str[last[lastPos]] > str[i-1]) {
        rm[last[lastPos--]] = 1; del--;
        --i;
      } else {
        last[++lastPos] = i-1;
      }
    }
    while (del && lastPos >= 0 && str[last[lastPos]] > str[len-1]) {
      rm[last[lastPos--]] = 1; del--;
    } 
    bool flag = 1;
    for(int i = 0, j = 0; i < len && j < left; ++i) {
       if (rm[i]) { continue; }
       ++j;
       if (flag && str[i] == '0') { continue; }
       flag = 0;
       putchar(str[i]);
     }
    if (flag) { putchar('0'); }
    putchar('\n');
  } 


#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////


#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  fflush(stdout);
  return 0;
}
