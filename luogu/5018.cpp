#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
int arr[maxN];
int l[maxN], r[maxN];

bool same(const int lt, const int rt) {
  if (!~lt && !~rt) { return 1; }
  if (!~lt || !~rt) { return 0; }
  if (arr[lt] != arr[rt]) { return 0; }
  return (same(l[lt], r[rt]) && same(l[rt], r[lt]));
}

int cnt(const int u) {
  return (~u ? 1+cnt(l[u])+cnt(r[u]) : 0);
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n+1) { std::cin >> arr[i]; }
  orep(i, 1, n+1) {
    std::cin >> l[i] >> r[i];
  }
  int ret = 0;
  orep(i, 1, n+1) {
    if (same(i, i)) { ret = std::max(ret, cnt(i)); }
  }
  std::cout << ret;

  return 0;
}
