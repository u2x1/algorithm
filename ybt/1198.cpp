#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <stdio.h>
#include <stdlib.h>

char str[20];
double f(){
  scanf("%s", str);
  switch(*str) {
    case '+':
        return f()+f();
    case '-':
        return f()-f();
    case '*':
        return f()*f();
    case '/':
        return f()/f();
    default:
        return atof(str);
  }
}

int main() {
#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%f\n", f());

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
