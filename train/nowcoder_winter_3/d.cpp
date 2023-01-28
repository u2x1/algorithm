#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  long long n; std::cin >> n;
  if (n & 1) {
    std::cout << "yukari";
  } else {
    std::cout << "kou";
  }

  return 0;
}
