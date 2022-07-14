#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
#include <algorithm>

struct student{
  char name[21];
  short score;
} stu[21];

bool operator<(student a, student b) {
  if(a.score == b.score){
    return (strcmp(a.name, b.name) < 0);
  }
  return a.score > b.score;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n && scanf("%s%hd", stu[i].name, &stu[i].score); ++i);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::stable_sort(stu, stu+n);
  for(int i = 0; i<n; ++i) {
    printf("%s %d\n", stu[i].name, stu[i].score);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
