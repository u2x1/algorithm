#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t; while(t--) {
    int n; std::cin >> n;
    int ret = 10;
    n = n*n-1;
    orep(i, 0, n) {
      std::string s; std::cin >> s;
      orep(i, 0, 4) {
        if (s[i] == '1') { ++ret; }
        if (s[i] == '2') { --ret; }
      }
    }
    std::cout << ret;
  }

  return 0;
}
