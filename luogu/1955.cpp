#include <iostream>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int fa1[maxN];
int find1(const int x) { if (x == fa1[x]) { return x; } return (fa1[x] = find1(fa1[x])); }

int xs[maxN], ys[maxN], es[maxN];

void solve() {
  int n; std::cin >> n;
  std::vector<int> v;
  orep(i, 0, n) {
    std::cin >> xs[i] >> ys[i] >> es[i];
    v.push_back(xs[i]); v.push_back(ys[i]);
  }
  v.erase(std::unique(v.begin(), v.end()), v.end());
  std::sort(v.begin(), v.end());
  orep(i, 0, n) {
    xs[i] = std::lower_bound(v.begin(), v.end(), xs[i]) - v.begin();
    ys[i] = std::lower_bound(v.begin(), v.end(), ys[i]) - v.begin();
  }
  orep(i, 0, 2*n+1) { fa1[i] = i; }
  orep(i, 0, n) {
    int x = xs[i], y = ys[i], e = es[i];
    if (e) {
      if (find1(x) == find1(y)) { continue; }
      fa1[find1(x)] = find1(y);
    }
  }
  orep(i, 0, n) {
    int x = xs[i], y = ys[i], e = es[i];
    if (!e) {
      if (find1(x) == find1(y)) { std::cout << "NO"; NL; return; }
    }
  }
  std::cout << "YES"; NL;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
