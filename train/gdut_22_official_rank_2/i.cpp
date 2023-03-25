#include <iostream>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

// const int maxN = 2e5+5;
// int arr[maxN];
// 
// std::vector<size_t> build(const std::string& s) {
//     std::vector<std::pair<std::string, size_t> > suffixes;
//     for (size_t i = 0; i < s.length(); ++i) {
//         suffixes.emplace_back(s.substr(i), i);
//     }
//     std::sort(suffixes.begin(), suffixes.end());
//     std::vector<size_t> sa(s.length());
//     for (size_t i = 0; i < s.length(); ++i) {
//         sa[i] = suffixes[i].second;
//     }
//     return sa;
// }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  std::cout << "b";
  orep(i, 1, k) { std::cout << "a"; }
  orep(i, k, n) { std::cout << "c"; }

  // NL;
  // std::string s = "b";
  // orep(i, 1, k) { s+= "a"; }
  // orep(i, k, n) { s += "c"; }
  // auto ret = build(s);
  // orep(i, 0, ret.size()) { std::cout << ret[i]<< " ";  }
  // std::cout << s;

  return 0;
}
