#include <iostream>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e6+5;
int dp[maxN], arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, qs; std::cin >> n >> qs;
  std::priority_queue<int> pq;

  int tmp;
  orep(i, 0, n) { std::cin >> tmp; pq.push(tmp); }

  int saved = 1;
  dp[0] = pq.top();
  orep(i, 0, qs) {
    int q; std::cin >> q;
    if (q > n*5) { std::cout << 1; NL; continue; }
    if (q >= saved) {
      for(; saved <= q; ++saved) {
        pq.push(__builtin_popcount(pq.top()));
        pq.pop();
        dp[saved] = pq.top();
      }
    }
    std::cout << dp[q]; NL;
  }
  
  return 0;
}
