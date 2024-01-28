#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int N, A, B, C; std::cin >> N >> A >> B >> C;
  std::string S; std::cin >> S;
  std::vector<int> mp(255);
  long long ret = 0;
  for(int i = 0, j = 0; i < N; ++i) {
    while(j < N && (mp['R'] < A || mp['M'] < B || mp['B'] < C)) {
      mp[S[j++]]++;
    }
    if ((mp['R'] >= A && mp['M'] >= B && mp['B'] >= C)) {
      ret += N - (j-1);
    }
    mp[S[i]]--;
  }
  std::cout << ret;

  return 0;
}
