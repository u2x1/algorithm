#include <iostream>
#include <cstdio>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];
double grade[maxN]; int gcnt;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, k; std::cin >> n >> m >> k;
  orep(i, 0, n) {
    int cnt = 0;
    int big = -1, sm = 101;
    long long sum = 0;
    orep(j, 0, m) {
      std::cin >> arr[cnt];
      big = std::max(big, arr[cnt]);
      sm = std::min(sm, arr[cnt]);
      cnt++; sum += arr[cnt-1];
    }
    sum -= big + sm;
    grade[gcnt++] = 1.0*sum/(m-2);
  }
  std::sort(grade, grade+gcnt);
  bool notfst = 0;
  orep(i, n-k, n) {
    if (notfst) { putchar(' '); }
    printf("%.3f", grade[i]);
    notfst = 1;
  }

  return 0;
}
