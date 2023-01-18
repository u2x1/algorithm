#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

struct st { int a; int b; };
bool operator<(st a, st b) { return a.a < b.a; }

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<st> v;
  orep(i, 0, n) {
    int a, b; std::cin >> a >> b;
    v.push_back({a, b});
  }
  std::sort(v.begin(), v.end());
  std::vector<int> real; int last = 1e9+1;
  std::vector<int> hash;
  orep(i, 0, n) {
    if (i && v[i].a == last) { real[real.size()-1] += v[i].b; }
    else { hash.push_back(v[i].a); real.push_back(v[i].b); }
    last = v[i].a;
  }
  orep(i, 0, real.size()) {
    std::cout << hash[i] << " ";
  } std::cout << NL;
  orep(i, 1, real.size()) {
    real[i] += real[i-1];
  }
  orep(i, 0, m) {
    int l, r; std::cin >> l >> r;
    const int realL = std::distance(hash.begin(), std::upper_bound(hash.begin(), hash.end(), l)) - 1;
    const int realR = std::distance(hash.begin(), std::upper_bound(hash.begin(), hash.end(), r)) - 1;
    std::cout << "r:" << realR << "l:" << realL << NL;
    int ll = realL < 0 ? 0 : real[std::max(0, std::min(realL, (int)hash.size()-1))]
      , rr = real[std::max(0, std::min(realR, (int)hash.size()-1))];
    std::cout << rr-ll << NL;
  }

  return 0;
}
