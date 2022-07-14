#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

#define UNIT 10000
#define LEN 4

int readInArray(char *str, int *num) {
  int pos = 0; const int len = strlen(str);
  const int preprocess = len % LEN;
  if (preprocess) {
    for(int i = 0; i < preprocess; ++i) {
      num[pos] = num[pos] * 10 + (str[i]-'0');
    } ++pos;
  }
  for (int i = preprocess; i < len;) {
    for (int j = 0; j < LEN; ++j) {
      num[pos] = num[pos] * 10 + (str[i] - '0');
      ++i;
    }
    ++pos;
  }
  return pos;
}

void mult(const int *a, const int *b, const int aLen, const int bLen, int *ans) {
  int carry = 0, pos;
  for(int i = aLen-1; i != -1; --i) {
    for(int j = bLen-1; j != -1; --j) {
      pos = aLen - 1 - i + bLen - 1 -j;
      ans[pos] = a[i] * b[j] + ans[pos] + carry;
      carry = ans[pos] / UNIT;
      ans[pos] %= UNIT;
//      printf("i: %d, j: %d, %d * %d = %d, carry = %d\n", i, j, a[i] , b[j], a[i]*b[j], carry);
//      printf("ans[%d]: %d\n", pos, ans[pos]);
    }
    if(carry) { ans[pos+1] += carry; }
    carry = 0;
  }
}

int main() {
  char mStr[101], nStr[101];
  scanf("%s%s", mStr, nStr);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int m[101], n[101];
  memset(m, 0, sizeof(m)); memset(n, 0, sizeof(n));
  const int mLen = readInArray(mStr, m);
  const int nLen = readInArray(nStr, n);
  int ans[101]; 
  memset(ans, 0, sizeof(ans));
  mult(m, n, mLen, nLen, ans);
  int i = mLen+nLen; while(--i > 0 && ans[i]==0);
  printf("%d", ans[i]);
  for(--i; i > -1; --i) {
    printf("%04d", ans[i]);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
