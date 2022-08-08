#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#define HIT printf("<%s> at ln%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PT(var, d) printf(#var": %"#d" \n", var);
#define NL printf("\n");
#include <cstdio>
#include <cstring>

void read(int a[]) {
  char c; int i = 1;
  for (; (c=getchar()) != EOF && c != '\n' && c != ' '; ++i) {
    a[i] = c - '0';
  } a[0] = i;
}

void print(int x[]) {
  int i;
  for(i = 1; i < 301 && x[i] == 0; ++i);
  const int len = *x;
  for(; i < len; ++i) { putchar(x[i]+'0'); }
  printf("\n");
}

inline bool greater_eq(int a[], int b[], int last_dg, int lb) {
  if (last_dg-(lb-1) != 0 && a[last_dg-(lb-1)] != 0) { return true; }
  for (int i = 1; i != lb; ++i) {
    if(a[last_dg+i-1] > b[i]) { return true; }
    if(a[last_dg+i-1] < b[i]) { return false; }
  }
  return true;
}

void div(int a[], int b[], int ans[], int rest[]) {
  int la = *a; int lb = *b;
  for (int i = la-1; i != -1; --i)  { rest[i] = a[i]; }
  for (int i = lb-1; i != la; ++i) {
    while (greater_eq(rest, b, i, lb)) {
      for (int j = lb-1; j != 0; --j) {
        int idx = i-(lb-1-j);
        rest[idx] -= b[j];
        if (rest[idx] < 0) {
          rest[idx-1] -= 1; rest[idx] += 10;
        }
      }
      ans[i] += 1;
    }
  } ans[0] = la;
}

int main() {

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int a[301], b[301];
  read(a);
  read(b);
  int ans[301], rest[301];
  memset(ans, 0, sizeof(ans));
  div(a,b,ans,rest);
  print(ans);
  print(rest);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
