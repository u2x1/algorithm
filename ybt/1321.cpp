#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
#include <algorithm>

int s;
char arr[241];

int main() {
  scanf("%s%d", arr, &s);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int len = strlen(arr);
  bool rm[len] = {0};
  int lastArr[len] = {0};
  int lastPos = 0;

  for(int i = 1; i < len-1 && s != 0; ++i) {
    if (lastPos == -1) { lastArr[++lastPos] = i; continue; }
    if (arr[lastArr[lastPos]] > arr[i]) {
      rm[lastArr[lastPos--]] = 1; --s; --i;
    } else if (arr[i] > arr[lastArr[lastPos]] && arr[i] > arr[i+1]) {
      rm[i] = 1; --s;
    } else {
      lastArr[++lastPos] = i;
    }
  }

  while (s!=0) { rm[len-s] = 1; --s; }
  bool flag=1;
  for(int i = 0; i < len; ++i) {
    if (rm[i]) { continue; }
    if (flag && arr[i] == '0') {continue;}
    flag = 0;
    putchar(arr[i]);
  } 

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
