#include <string>
#include <iostream>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::string country[n];
  for(int i = 0; i < n; ++i) {
    std::cin >> country[i];
  }

  std::sort(country, country + n);
  for(int i = 0; i < n; ++i) {
    std::cout << (country[i]) << std::endl;
  }

  return 0;
}
