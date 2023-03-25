#include <iostream>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e3+5;
long long arr[maxN][maxN];
// long long f[105][105][105];
long long f[305][305];
long long cnt[maxN];
const int mod = 998244353;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 1, n+1) {
    orep(j, 1, m+1) {
      std::cin >> arr[i][j];
      cnt[i] = (cnt[i] + arr[i][j]) % mod;
    }
  }
  long long ret = 1ll;
  orep(i, 1, n+1) { ret = (ret * cnt[i] % mod + ret) % mod; }

  long long off = 0;
  orep(j, 1, m+1) {
    // NL; std::cout << "for j " << j; NL;
    memset(f, 0, sizeof(f));
    f[0][n] = 1;
    orep(i, 0, n) {
      // f[i][0][0] = 1;
      // f[i][1][0] = f[i-1][1][0] + arr[i][j];
      // f[i][0][1] = f[i-1][0][1] + cnt[i]-arr[i][j];
      //// orep(a, 0, n) {
      ////   orep (b, 0, n) {
      ////     f[i+1][a][b] += f[i][a][b];
      ////     f[i+1][a][b] %= mod;
      ////     f[i+1][a][b+1] += f[i][a][b] * (cnt[i+1]-arr[i+1][j]);
      ////     f[i+1][a][b+1] %= mod;
      ////     f[i+1][a+1][b] += f[i][a][b] * (arr[i+1][j]);
      ////     f[i+1][a+1][b] %= mod;
      ////     // f[i][a][b] += f[i-1][a][b] + f[i-1][a][b-1]*(cnt[i]-arr[i][j]) + f[i-1][a-1][b]*arr[i][j];
      ////     // std::cout << i <<"," << a <<"," << b << ": "<< f[i][a][b]; NL;
      ////   }
      //// }
      orep(d, 0, 2*n) {
        f[i+1][d] += f[i][d];
        f[i+1][d] %= mod;
        f[i+1][d+1] += f[i][d] * arr[i+1][j] % mod;
        f[i+1][d+1] %= mod;
        f[i+1][d-1] += f[i][d] * (cnt[i+1]-arr[i+1][j]) % mod;
        f[i+1][d-1] %= mod;
      }
    }
    // NL; std::cout << "for j " << j; NL;
    orep(d, n+1, 2*n+1) {
      // std::cout << n <<"," << d-n << ": "<< f[n][d]; NL;
      off += f[n][d];
      off %= mod;
    }
    // NL;
    //// orep(b, 0, n+1) {
    ////   orep(a, b+1, n+1) {
    ////     off += f[n][a][b];
    ////     off %= mod;
    ////     // std::cout << n <<"," << a <<"," << b << ": "<< f[n][a][b]; NL;
    ////   }
    //// }
  }

  ret = (ret-1+mod) % mod;
  // std::cout << ret; NL;
  // std::cout << off; NL;
  std::cout << (ret-off+mod) % mod;
  return 0;
}
