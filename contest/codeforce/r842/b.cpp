#include <cstdio>
#include <queue>
#include <cmath>
#include <climits>
#include <set>
#include <algorithm>

#define NL putchar(10);

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n, k; scanf("%d%d", &n, &k);
    int max = -1; int tmp, mx = INT_MAX;
    std::set<int> st;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &tmp);
      st.insert(tmp);
      if (tmp < max) {
        mx = std::min(mx, *st.upper_bound(tmp));
      }
      max = std::max(max, tmp);
    }
    printf("%.0f", INT_MAX == mx ? 0 : ceil(1.0*(1+n-mx)/k));
    NL;
  }
  return 0;
}
