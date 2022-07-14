#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

struct student{
  int id;
  int chinese;
  int total;
} stu[301];

bool cmpStu(student a, student b) {
  if (a.total == b.total) {
    if (a.chinese == b.chinese) {
      return a.id < b.id;
    }
    return a.chinese > b.chinese;
  }
  return a.total > b.total;
}

void getTop5(int n) {
  int top;
  for(int i = 0; i < 5; ++i) {
    top = i;
    for(int j = i+1; j < n; ++j) {
      if (cmpStu(stu[j], stu[top])) {
        top = j;
      }
    }
    std::swap(stu[i], stu[top]);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int a, b, c;
  for(int i = 0; i<n; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    stu[i].id = i+1;
    stu[i].chinese = a;
    stu[i].total = a+b+c;
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  getTop5(n);
  for(int i = 0; i < 5 && i < n; ++i){
    printf("%d %d\n", stu[i].id, stu[i].total);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
