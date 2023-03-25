#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
long long dp[35][35];
int root[35][35];

void out(const int l, const int r) {
  if (l >= r) { return; }
  std::cout << root[l][r]+1 << " ";
  // std::cout << root[l][r]+1 << " " << r; NL;
  out(l, root[l][r]);
  out(root[l][r]+1, r);
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) { std::cin >> arr[i]; dp[i][i] = 1; dp[i][i+1] = arr[i]; root[i][i+1] = i; }
  orep(s, 2, n+1) {
    orep(i, 0, n) {
      orep(k, i, i+s) {
        if (dp[i][k]*dp[k+1][i+s]+arr[k] > dp[i][i+s]) {
          root[i][i+s] = k;
          dp[i][i+s] = dp[i][k]*dp[k+1][i+s]+arr[k];
        }
        // std::cout << i << "," << i+s << ": " << dp[i][i+s]; NL;
      }
    }
  }
  std::cout << dp[0][n]; NL;
  out(0, n);


  return 0;
}
