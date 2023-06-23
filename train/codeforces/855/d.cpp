#include <iostream>
#include <set>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

using ui64 = unsigned long long;

const int X1 = 131;
const int X2 = 1331;
ui64 h1[maxN], h2[maxN];
ui64 h1rev[maxN], h2rev[maxN];
ui64 x1mi[maxN], x2mi[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  x1mi[0] = x2mi[0] = 1;
  orep(i, 1, maxN) {
    x1mi[i] = x1mi[i-1] * X1;
    x2mi[i] = x2mi[i-1] * X2;
  }
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    orep(i, 0ul, s.size()) {
      h1[i+1] = h1[i]*X1 + s[i];
      h2[i+1] = h2[i]*X2 + s[i];
    }
    std::set<std::pair<ui64, ui64>> st;
    // st.insert({h1[s.size()]-h1[2]*x1mi[s.size()-2], h2[s.size()] - h2[2]*x2mi[s.size()-2]});
    orep(i, 0ul, s.size()-1) {
      st.insert({h1[s.size()]-h1[2+i]*x1mi[s.size()-2-i]+h1[i]*x1mi[s.size()-i-2], 
                 h2[s.size()]-h2[2+i]*x2mi[s.size()-2-i]+h2[i]*x2mi[s.size()-i-2]});
    }
    std::cout << st.size(); NL;
  }

  return 0;
}
