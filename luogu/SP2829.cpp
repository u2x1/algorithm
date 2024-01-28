#include<bits/stdc++.h>

const int mod = 1e9;

void solve()
{
    int n, m;
    std::cin >> n >> m;
    int len = 1 << m;
    len--;
    std::vector<int> li(n + 1);
    std::vector<int> dp(len + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> li[i];
    for (int i = 0; i <= len; i++)
        dp[i] = (i % li[1] != 0);
    std::vector<int> ndp(len + 1);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= len; j++)
            for (int k = j; k > 0; k = (k - 1) & j)
                ndp[k] = (ndp[k] + dp[j]) % mod;
        for (int j = 0; j <= len; j++)
            if (j % li[i] == 0) ndp[j] = 0;
        std::swap(ndp, dp);
        ndp.assign(len + 1, 0);
    }
    int ans = 0;
    for (int i = 0; i <= len; i++)
        ans = (ans + dp[i]) % mod;
    std::cout << ans << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--)
        solve();
}
// #include <bits/stdc++.h>
// 
// #define all(x)      x.begin(), x.end()
// #define NL          std::cout << '\n'
// 
// using lnt = long long;
// 
// const int inf = 0x3f3f3f3f;
// const lnt linf = 1ll << 62;
// 
// constexpr int mo = 1e9;
// 
// signed main() {
//   std::ios::sync_with_stdio(0), std::cin.tie(0);
//   int t; std::cin >> t;
//   while (t--) {
//     int n, m; std::cin >> n >> m;
//     int u = (1 << m) - 1;
// 
//     std::vector<int> c(n);
//     for (auto &x : c) {
//       std::cin >> x;
//     }
// 
//     std::vector<int> f(u+1);
//     f[0] = 1;
//     for (int i = 0; i < n; ++i) {
// 
//       for (int j = 0; j < m; ++j) {
//         for (int s = (1 << m) - 1; ~s; --s) {
//           if ((s >> j & 1)) { (f[s] += f[s ^ (1 << j)]) %= mo; }
//         }
//       }
// 
//       for (int s = (1 << m) - 1; s > -1; s -= 2) {
//         std::swap(f[s], f[s ^ u]);
//       }
// 
//       for (int s = (1 << m) - 1; ~s; --s) {
//         if (s % c[i] == 0) { f[s] = 0; }
//       }
// 
//     }
// 
//     lnt ret = 0;
//     for (int s = (1 << m) - 1; ~s; --s) {
//       (ret += f[s]) %= mo;
//     }
//     std::cout << ret; NL;
//   }
// 
//   return 0;
// }
