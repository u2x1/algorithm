#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  
  while(1) {
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    if (!a&&!b&&!c&&!d&&!e&&!f) { break; }
    int box = f+e+d;
    a -= 11*e;
    b -= d*5;
    if (b < 0) { a -= (-b)*4; b = 0; }

    box += c / 4; c %= 4; ++box;
    if (c == 1) { 
      b -= 5;
      a -= 7 + (b<0?(-b)*4:0);
    } else if ( c == 2) {
      b -= 3;
      a -= 6 + (b<0?(-b)*4:0);
    } else if (c == 3) {
      b -= 1;
      a -= 5 + (b<0?(-b)*4:0);
    } else { --box; }
    if (b > 0) {
      box += b/9; b%=9;
      if (b>0) {
        ++box;
        a -= 36 - b*4;
      }
    }
    if (a > 0) {
      box+=a/36; a%=9;
      if (a>0) { ++box; }
    }
    printf("%d\n", box);
  }


#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////


#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
