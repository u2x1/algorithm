#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  int n, m;
  scanf("%d ", &n);
  char arr[2][n][n];
  char c;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n && (c=getchar()) != '\n'; ++j) {
      if (c == '@') {++ans;}
      arr[0][i][j] = c;
      arr[1][i][j] = '.';
    }
  }
  scanf(" %d", &m);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  for(int d = 2; d <= m; ++d) {
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if (arr[0][i][j] != '.') { arr[1][i][j] = arr[0][i][j]; continue; }
        if ((i+1 <  n && arr[0][i+1][j] == '@')
         || (j+1 <  n && arr[0][i][j+1] == '@')
         || (i-1 > -1 && arr[0][i-1][j] == '@')
         || (j-1 > -1 && arr[0][i][j-1] == '@'))
          { arr[1][i][j] = '@'; ++ans; } 
      }
    }
    memcpy(*arr[0], *arr[1], n*n*sizeof(arr[0][0][0]));
//    for(int i = 0; i < n; ++i) {
//      for(int j = 0; j < n; ++j) {
//        putchar(arr[0][i][j]);
//      }
//      putchar('\n');
//    }
//      putchar('\n');
  }
  printf("%d", ans);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
