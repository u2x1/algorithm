#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

char str[7]; int len;
bool mark[27];
char output[7];

void f(int pos){
  if (pos == len) {
    output[pos] = '\0';
    printf("%s\n", output);
  }
  for (int i = 0; i<len; ++i) {
    if (mark[*str+i]) { continue; }
    output[pos] = str[i]; mark[*str+i] = 1;
    f(pos+1);
    mark[*str+i] = 0;
  }
}

int main() {
  scanf("%s", str);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  len = strlen(str);
  f(0);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
