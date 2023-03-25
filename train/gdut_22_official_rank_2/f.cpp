#include <iostream>
#include <algorithm>
#include <string>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
std::string arr[maxN];

bool check(const std::string &s) {
  // std::cout << s.substr(s.size()-4, 4); NL;
  if (s.size() < 4) { return 0; }
  if (s.substr(s.size()-4, 4) == ".eoj") { return 1; }
  return 0;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    std::cin >> arr[i];
    orep(j, 0ul, arr[i].size()) { if (arr[i][j] == '/') { arr[i][j] = '!'; } }
  }
  // std::cout << "......" << (int)('!' - 0); NL;
  std::sort(arr, arr+n);
  // orep(i, 0, n) { std::cout << arr[i]; NL; }
  int ret = check(arr[0]);
  orep(i, 1, n) {
    if (arr[i-1].size() < arr[i].size()
        && arr[i].substr(0, arr[i-1].size()) == arr[i-1] && arr[i][arr[i-1].size()] == '!' && check(arr[i-1])) { ret--; }
    if (check(arr[i])) { ret++; }
  }
  std::cout << ret;

  return 0;
}
