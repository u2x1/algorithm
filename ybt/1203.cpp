#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

char ret[101]; int pos = -1;
char raw[101];
char *mark[50];

char c;
void f(const int lCnt) {
  c = getchar(); ++pos;
  raw[pos] = c;

  if(c == ')') {
    if (lCnt == 0) {
      ret[pos] = '?';
      f(lCnt);
    } else {
      ret[pos] = ' ';
      *mark[lCnt-1] = ' ';
      f(lCnt-1);
    }
  } else if (c == '(') {
    ret[pos] = '$';
    mark[lCnt] = &ret[pos];
    f(lCnt+1);
  } else if (c == '\n' || c==EOF) {
    for(int i=0; i<pos;++i) {putchar(raw[i]);}
    putchar('\n');
    for(int i=0; i<pos;++i) {putchar(ret[i]);}
    putchar('\n');
    pos = -1;
    if (c==EOF) {return;}
    f(0);
  } else {
    ret[pos] = ' ';
    f(lCnt);
  }
}

int main() {
  f(0);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
