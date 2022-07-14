#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  char c;
  char s[201];
  int sLen = 0;
  for (; (c=getchar()) != '\n'; ++sLen) {
    s[sLen] = c;
  } s[sLen] = '\0';
  char a[101], b[101];
  scanf("%s%s", a, b);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  char temp[101]; int tempPos = -1;
  for (int i = 0; i <= sLen;) {
    c = s[i];
//    printf("c: '%c'\n", s[i]);
    if (c != ' ' && c != '\0') {
      temp[++tempPos] = c;
    } else {
      temp[++tempPos] = '\0';
//      printf("temp: %s\n", temp);
      if (strcmp(temp, a) == 0) {
        printf("%s ", b);
      } else {
        printf("%s ", temp);
      }
      tempPos = -1;
    }
    ++i;
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
