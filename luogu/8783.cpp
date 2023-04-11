#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 5e2+5;
int arr[maxN][maxN];
long long sum[maxN][maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, k; std::cin >> n >> m >> k;
  orep(i, 1, n+1) {
    orep(j, 1, m+1) {
      std::cin >> arr[i][j]; sum[i][j] = sum[i][j-1] + arr[i][j];
    }
  }
  orep(i, 1, n+1) {
    orep(j, 1, m+1) {
      sum[i][j] += sum[i-1][j];
    }
  }

  long long ret = 0;
  for(int i = n; i > 0; --i) {
    for(int j = m; j > 0; --j) {
      // int cur = 0;
      for(int l = 1, h = i; l <= j; ++l) {
        if (h > 0 && sum[i][j] - sum[h-1][j] - sum[i][l-1] + sum[h-1][l-1] > k) { continue; }
        while(h > 0 && sum[i][j] - sum[h-1][j] - sum[i][l-1] + sum[h-1][l-1] <= k) { --h; }
        ++h;
        ret += (i-h)+1;
        // cur += (i-h)+1;
        // std::cout << l << ", " << h << " is ans of " <<  i << ',' << j; NL;
      }
      // std::cout << cur << " is ans of " <<  i << ',' << j; NL;
    }
  }
  std::cout << ret;


  return 0;
}
