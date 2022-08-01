#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
#include <algorithm>

bool revCmp(const int a, const int b) { return a > b; }

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i<n && ~scanf("%d", &arr[i]); ++i);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////
  
  int maxCnt = 0;
  for(int mid = 1; mid < n; ++mid){
    const int midNum = arr[mid];
    int dp1[mid];
    memset(dp1, 0x1f, sizeof(dp1));
    const int inf1 = dp1[0];
    for(int i = 0; i<mid; ++i) {
      if(arr[i] < midNum) { 
        *(std::lower_bound(dp1, dp1+mid, arr[i])) = arr[i];
      }
    }
    int rm1 = 0;
    while(rm1 < mid && dp1[rm1] != inf1) { ++rm1; }

    int dp2[n-mid] = {0};
    const int dp2len = n-mid-1;
    for(int i = mid+1; i<n; ++i) {
      if(arr[i] < midNum) {
        *(std::lower_bound(dp2, dp2+dp2len, arr[i], revCmp)) = arr[i];
      }
    }
    int rm2 = 0;
    while(dp2[rm2] != 0) { ++rm2; }

    maxCnt = std::max(maxCnt, rm1+rm2);
  }
  printf("%d", n-maxCnt-1);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
