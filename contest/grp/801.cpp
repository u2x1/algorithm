#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

char arr[1000001], tmp[1000001];

int main() {
  int l=0, r=0;
  char c;
  for(; (c=getchar()) >= '0' && c <= '9'; ++r) {
    tmp[r] = c-'0';
  } --r;

  for(int i=r, j=0; i!=-1; --i, ++j) {                       // 将输入倒序存入char *arr
    arr[j] = tmp[i];
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  while(l < r) {                                             // 终止条件: 当前串只剩一位
    const int sum = arr[l] + arr[r];                         // 当前串最高位与最低位的和, 0<=sum<=18
    if(sum < 10) { arr[r] = sum; }                           // 若sum是个位数，将原串最高位替换为sum
    else { arr[r] = (sum%10); arr[++r] = (sum/10); }         // 否则，将原串最高位替换为sum的低位，再将原串长度+1
                                                             //   再将最高位替换为sum的高位
    ++l;                                                     // 移除最低位
    // 取消注释以查看调试信息
    //// for(int i=0; i <= r; ++i) { putchar(arr[i]+'0'); } putchar(10);
    //// for(int i=0; i <= r; ++i) { 
    ////   if(i==l) { putchar('l'); }
    ////   else if (i==r) { putchar('r'); }
    ////   else { putchar(' '); } }
    //// putchar(10);
  }
  printf("%d", arr[r]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
