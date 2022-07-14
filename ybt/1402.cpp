#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  int key[101];
  char msg[1001];
  char c; int kLen = 0;
  for (; (c=getchar()) != '\n'; ++kLen) {
    if (c <= 'Z') { key[kLen] = c - 'A'; }
    else { key[kLen] = c - 'a'; }
  }
  scanf("%s", msg);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int kPos = 0;
  int msgLen = strlen(msg);
  for (int i = 0; i < msgLen; ++i) {
    if (kPos == kLen) { kPos = 0; }
//    printf("msg[i]: '%c', key[%d]: '%d'\n", msg[i], kPos, key[kPos]);
    if (msg[i] <= 'Z') { msg[i] = 'A'+ ((26+(msg[i]-'A'-key[kPos])) % 26); }
    else { msg[i] = 'a'+ ((26+(msg[i]-'a'-key[kPos])) % 26); }
    ++kPos;
  }

  printf("%s", msg);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
