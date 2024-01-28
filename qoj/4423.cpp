#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

inline lnt dis(std::pair<lnt, lnt> a, std::pair<lnt, lnt> b) {
  auto [x1, y1] = a;
  auto [x2, y2] = b;
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int t; std::cin >> t;
  while (t--) {
    int n; std::cin >> n;
    int k; std::cin >> k;

    std::vector<std::pair<lnt, lnt>> pts(n);

    std::vector<char> dead(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> pts[i].first >> pts[i].second;
    }

    std::vector<int> st({0});
    st.reserve(k);
    dead[0] = 1;

    std::vector<lnt> nearest(pts.size(), linf);

    std::vector<int> grp(n);
    
    for (int _ = 1; _ <= k; ++_) {
      const auto pre = pts[st.back()];
      std::pair<lnt, int> nxt = {-1, 0};
      for (int i = 0, N = pts.size(); i < N; ++i) {
        if (dead[i]) { continue; }
        lnt d = dis(pre, pts[i]);
        if (nearest[i] > d) { nearest[i] = d; grp[i] = grp[st.back()]; }
        nxt = std::max(nxt, {nearest[i], i});
      }
      if (_ == k) { break; }
      grp[nxt.second] = st.size();
      st.emplace_back(nxt.second);
      dead[nxt.second] = 1;
    }

    for (auto x : grp) { std::cout << x + 1 << " "; } NL;

  }

  return 0;
}
