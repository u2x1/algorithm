#include <iostream>
#include <vector>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 5e5+5;
long long ret[maxN], times_of_n[maxN];

void brk(const int x) {
  const int end = sqrt(x) + 1;
  orep(i, 1, end) {
    if (x%i) { continue; }
    times_of_n[i]++;
    const int oth = x/i;
    if (oth != i) { times_of_n[oth]++; }
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::vector<int> arr;
  int n, q; std::cin >> n >> q;
  orep(i, 0, n) {
    int tmp; std::cin >> tmp;
    ret[i] = times_of_n[tmp];
    brk(tmp); arr.emplace_back(tmp);
  }
  orep(i, 0, q) {
    int op, x; std::cin >> op >> x;
    if (op == 1) {
      ret[arr.size()] = times_of_n[x];
      brk(x); arr.emplace_back(x);
    } else {
      std::cout << times_of_n[arr[x-1]] - ret[x-1] - 1; NL;
    }
  }
  return 0;
}
