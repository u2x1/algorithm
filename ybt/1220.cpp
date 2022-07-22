#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int dup(char *l, char *r, const int lenl, const int lenr) {
  for(int lPos = lenl-1; lPos != -1; --lPos) {
    int cnt = 0;
    int nowLPos = lPos;
    while(cnt < lenr && l[nowLPos] == r[cnt]){
      ++nowLPos; ++cnt;
    }
    if (nowLPos == lenl) {
      if (lenl != lenr && (cnt == lenr || cnt == lenl)) { continue; }
//      printf("%s-%s %d \n", l, r, cnt);
      return cnt;
    }
  }
  return 0;
}

int used[21];
char word[21][21];
int n;
int maxLen;

void f(char *ori, const int len) {
  for(int i = 0; i < n; ++i) {
    if (used[i] == 2) { continue; }
    const int lenl = strlen(ori);
    const int lenr = strlen(word[i]);
    int extra = dup(ori, word[i], lenl, lenr);
    if (extra) {
      used[i] += 1;
      f(word[i], len+lenr-extra);
      used[i] -= 1;
    }
  }
  if(len > maxLen) {
    maxLen = len;
  }
}

int main() {
  char c;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%s", word[i]);
  }
  scanf(" %c", &c);
  for(int i = 0; i < n; ++i) {
    if (word[i][0] == c) {
      used[i] = 1; f(word[i], strlen(word[i])); used[i] = 0;
    }
  }


#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", maxLen);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
