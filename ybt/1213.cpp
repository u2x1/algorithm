#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

bool b[8], dl[15], dr[15];
bool arr[8][8];

int cnt;
void f(int pos) {
  if (pos == 8) {
    printf("No. %d\n", ++cnt);
    for(int i = 0; i<8; ++i) {
      for(int j = 0; j<8; ++j) {
        putchar(arr[j][i] + '0'); putchar(' ');
      }
      putchar('\n');
    }
    return;
  }
  for(int i = 0; i < 8; ++i) {
    if (!b[i] && !dl[pos-i+7] && !dr[pos+i]) {
      arr[pos][i] = 1; b[i] = 1; dl[pos-i+7] = 1; dr[pos+i] = 1;
      f(pos+1);
      arr[pos][i] = 0; b[i] = 0; dl[pos-i+7] = 0; dr[pos+i] = 0;
    }
  }
}

int main() {

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  f(0);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
