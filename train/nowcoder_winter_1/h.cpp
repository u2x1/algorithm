#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t; while(t--) {
    int n; std::cin >> n;
    int ones = 0, twos = 0;
    orep(i, 0, n) {
      std::string s; std::cin >> s;
      orep(i, 0, 4) {
        if (s[i] == '1') { ++ones; }
        if (s[i] == '2') { ++twos; }
      }
    }
    if ()
  }

  return 0;
}
