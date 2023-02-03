#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';


int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  const int r = n/3;
  orep(i, 0, r) {
    std::cout << "1 1 2 ";
  }
  n %= 3;
  int arr[3] = {1,1,2};
  orep(i, 0, n) {
    std::cout << arr[i] << " ";
  }

  return 0;
}
