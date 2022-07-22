#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
#include <algorithm>

bool isPrimes(int a, int b) {
  if (a < b) { std::swap(a, b); }
  while(b != 0) {
    std::swap(a,b);
    b %= a;
  }
  if (a == 1) { return true; }
  return false;
}

int n;
bool used[11];
int arr[11], min = 999999;
void f(int grpCnt) {
  bool stop = 1;
  for(int i = 0; i < n; ++i) {
    if (used[i]) { continue; }
    stop = 0;
    used[i] = 1;
    int currGrp[11], currGrpPos = 1; currGrp[0] = i;
    for(int k = 0; k < n; ++k) {
      if (used[k]) { continue; }
//      printf("compare %d with %d\n", k, i);
      bool flag = 1;
      for(int j = 0; j < currGrpPos; ++j) {
        if (!isPrimes(arr[k], arr[currGrp[j]])) { flag=0; }
      }
      if(flag) {
//        printf("picked %d\n", k);
        currGrp[currGrpPos++] = k;
        used[k] = 1;
      }
    }
//    printf("enter grp%d\n", grpCnt+1);
    f(grpCnt+1);
//    printf("exit grp%d\n", grpCnt+1);
    for(int p = 0; p < currGrpPos; ++p) {
//      printf("%d ", arr[currGrp[p]]);
      used[currGrp[p]] = 0;
    }
//    printf("\n");
  }
  if(stop) {
    if(min > (grpCnt)) {
      min = grpCnt;
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; ++i) {
    scanf("%d", &arr[i]);
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  f(0);
  printf("%d", min);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
