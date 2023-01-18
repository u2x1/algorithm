#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    int tmp; long long sum = 0;
    orep(i, 0, n) {
      std::cin >> tmp;
      sum += abs(tmp);
    }
    std::cout << 2*n*sum <<NL;
  }

  return 0;
}
