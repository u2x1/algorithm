#include <cstdio>
#include <algorithm>
#include <set>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN], rise[maxN];

int main() {
  int tmp, n=0;
  while(~scanf("%d",&tmp)) {
    arr[n++] = tmp;
  }
  int riseN = 0;
  orep(i, 0, n) {
    int* it = std::upper_bound(rise, rise+riseN+1, arr[i], std::greater<int>());
    *it = arr[i];
    if (it-rise+1 > riseN) { ++riseN; }
  }
  printf("%d", riseN); NL;

  std::set<int> system;
  orep(i, 0, n) {
    auto it = system.lower_bound(arr[i]);
    if (it != system.cend()) {
      system.erase(it);
    }
    system.insert(arr[i]);
  }
  printf("%lu", system.size()); NL;
  return 0;
}
