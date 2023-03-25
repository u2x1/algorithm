#include <iostream>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e6+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    int sum = 0;
    orep(i, 0, n) {
      std::cin >> arr[i];
      sum ^= arr[i];
    }
    std::set<int> s;
    if (sum) { std::cout << "YES"; goto fend; }
    orep(i, 0, n) {
      if (!arr[i])  { continue; }
      s.insert(arr[i]);
    }
    if (s.size() >= 2) { std::cout << "YES"; goto fend; }
    std::cout << "NO";
fend: NL;
  }
  return 0;
}
