#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

struct student{
  long id;
  double grade;
} stu[110];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  --k;
  for(int i = 0; i<n && scanf("%ld%lf", &stu[i].id, &stu[i].grade); ++i);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  for(int j = n-1; j>=0; --j){
    for(int i = 0; i < j; ++i) {
      if (stu[i].grade < stu[i+1].grade) {
        std::swap(stu[i], stu[i+1]);
      }
    }
  }
  printf("%ld %g", stu[k].id, stu[k].grade);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
