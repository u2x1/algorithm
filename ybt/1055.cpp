#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int year;
  scanf("%d", &year);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  // 1.普通闰年:公历年份是4的倍数,且不是100的倍数,为普通闰年(如2004年、2020年就是闰年)。
  // 2.世纪闰年:公历年份是整百数,必须是400的倍数,才是世纪闰年(如1900年不是世纪闰年,而2000年就是世纪闰年)。
  bool isRun = false;
  if (year % 100 == 0) { // 如果year能被100整除
    if (year % 400 == 0) {
      isRun = true;
    }
  } else {
    if (year % 4 == 0) {
      isRun = true;
    }
  }

  if (isRun) {
    printf("Y");
  } else { printf("N"); }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
