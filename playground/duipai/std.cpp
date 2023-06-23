#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
      std::cin >> l[i] >> r[i];
    }
    std::vector<int> xs = l;
    xs.insert(xs.end(), r.begin(), r.end());
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    for (int i = 0; i < n; i++) {
      l[i] = (int) (lower_bound(xs.begin(), xs.end(), l[i]) - xs.begin());
      r[i] = (int) (lower_bound(xs.begin(), xs.end(), r[i]) - xs.begin());
    }
    int sz = (int) xs.size();
    std::vector<std::vector<bool>> good(sz, std::vector<bool>(sz, false));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (std::max(l[i], l[j]) <= std::min(r[i], r[j])) {
          good[std::min(l[i], l[j])][std::max(r[i], r[j])] = true;
        }
      }
    }
    for (int i = sz - 1; i >= 0; i--) {
      for (int j = i; j < sz; j++) {
        if (good[i][j] && i > 0) {
          good[i - 1][j] = true;
        }
        if (good[i][j] && j < sz - 1) {
          good[i][j + 1] = true;
        }
      }
    }
    std::vector<int> dp(sz + 1);
    for (int i = 0; i < sz; i++) {
      dp[i + 1] = std::max(dp[i + 1], dp[i]);
      for (int j = i; j < sz; j++) {
        if (good[i][j]) {
          dp[j + 1] = std::max(dp[j + 1], dp[i] + 1);
        }
      }
    }
    std::cout << n - 2 * dp[sz] << '\n';
  }
  return 0;
}
