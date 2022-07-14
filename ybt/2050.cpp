#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstring>
#include <cstdio>
using namespace std;

int main() {
  char a[61], b[31];
  scanf("%s%s", a, b);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  char a_cpy[31];
  int la = strlen(a), lb = strlen(b);
  if (la < lb) { strcpy(a_cpy, b); strcpy(b, a); strcpy(a, a_cpy); }
  else if (la > lb) { strcpy(a_cpy, a); }
  if (strstr(strcat(a, a_cpy), b) == NULL) {
    printf("false");
  } else {
    printf("true");
  }

#ifdef BENCHMARK                                              ////
  // cout << "\n  run time: "                                    ////
  //   << (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000  ////
  //   << " ms\n";                                               ////
#endif                                                        ////

  return 0;
}
