#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int len;
int cnt = -1;

void f(const int n, char *arr) {
  printf("step%2d:", ++cnt);
  for(int i = 0; i<len && putchar(arr[i]); ++i);
  putchar(10);
  arr[n] = arr[n-1] = '-';
  arr[2*n+1] = '*'; arr[2*n] = 'o';
  printf("step%2d:", ++cnt);
  for(int i = 0; i<len && putchar(arr[i]); ++i);
  putchar(10);
  if (n == 4) { 
    printf("step%2d:ooo*o**--*", ++cnt);
    for(int i = 10; i<len && putchar(arr[i]); ++i);
    putchar(10);
    printf("step%2d:o--*o**oo*", ++cnt);
    for(int i = 10; i<len && putchar(arr[i]); ++i);
    putchar(10);
    printf("step%2d:o*o*o*--o*", ++cnt);
    for(int i = 10; i<len && putchar(arr[i]); ++i);
    putchar(10);
    printf("step%2d:--o*o*o*o*", ++cnt);
    for(int i = 10; i<len && putchar(arr[i]); ++i);
    return;
  }
  arr[n] = arr[n-1] = '*';
  arr[2*n-1] = arr[2*n-2] = '-';
  f(n-1,arr);
}

int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  len = 2*n+2;
  char arr[len];
  for(int i = 0; i < n; ++i) {
    arr[i] = 'o'; arr[i+n] = '*';
  } arr[len-1] = arr[len-2] = '-';
  f(n, arr);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
