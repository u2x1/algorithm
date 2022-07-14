#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

char toChar(int x) {
  if (x < 10) { return x+'0'; }
  switch(x) {
    case 10:
      return 'A'; break;
    case 11:
      return 'B'; break;
    case 12:
      return 'C'; break;
    case 13:
      return 'D'; break;
    case 14:
      return 'E'; break;
    case 15:
      return 'F'; break;
  } return 0;
}

void trans(const int num, const int d, char *ret, int &len) {
  if (num == 0) { return; }
  *ret = toChar(num % d);
  ++len;
  trans(num/d, d, ret+1, len);
}


int main() {
  int i, d;
  scanf("%d%d", &i, &d);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  char s[100000];
  int len = 0;
  trans(i, d, s, len);
  s[len] = '\0';
  for (int i = len-1; i != -1; --i) {
    putchar(s[i]);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
