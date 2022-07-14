#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

struct pep{
  int id; int grade;
};

bool operator<(pep a, pep b) { 
  if (a.grade == b.grade) {
    return a.id < b.id;
  }
  return a.grade > b.grade;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  pep arr[n];
  for(int i=0; i<n && scanf("%d %d", &arr[i].id, &arr[i].grade); ++i);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  m *= 1.5; --m;
  std::sort(arr, arr+n);
  int idd = arr[m].grade; int finalAns;
  for(finalAns = m; finalAns < n; ++finalAns) {
    if (arr[finalAns].grade != idd) { break; }
  }
  printf("%d %d\n", idd, finalAns);
  for(int i = 0; i < finalAns; ++i) {
    printf("%d %d\n", arr[i]. id, arr[i].grade);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
