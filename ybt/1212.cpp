#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#define MAX(a,b) (((a)>(b))?(a):(b))
int r, s;
bool walked[26];
char table[1001][21];

int search(const int, const int, const int);

int diveIn(const int x, const int y, const int pos) {
  int ret = 0;
  if (!walked[table[y][x] - 'A']) {
    ret = search(x, y, pos);
  }
  return ret;
}

int search(const int x, const int y, const int pos) {
  int a = 0, b = 0, c = 0, d = 0;
  const int idx = table[y][x] - 'A'; 
  walked[idx] = 1;
  if (x+1<s)  { a = diveIn(x+1, y, pos+1); }
  if (x-1>=0) { b = diveIn(x-1, y, pos+1); }
  if (y+1<r)  { c = diveIn(x, y+1, pos+1); }
  if (y-1>=0) { d = diveIn(x, y-1, pos+1); }
  walked[idx] = 0;

//  printf("(%d,%d) ", x, y);
//  printf("(%d,%d,%d,%d,%d)\n", a, b, c, d, pos);
  if (!a && !b && !c && !d) { return pos; }
  return MAX(a,MAX(b,MAX(c, d)));
}

int main() {
  scanf("%d%d", &r, &s); getchar();
  for(int i=0; i<r; ++i) {
    for(int j=0; j<s; ++j) {
      table[i][j] = getchar();
    }
    getchar();
  }
//  for(int i=0; i<r; ++i) {
//    for(int j=0; j<s; ++j) {
//      putchar(table[i][j]);
//    }
//    putchar('\n');
//  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", search(0,0,1));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
