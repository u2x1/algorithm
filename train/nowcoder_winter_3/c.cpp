#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  if (!(n%5)) {
    for(int j=1; j < n; j+=5) {
      std::cout << j+2 << " " << j+3 << " " << j+4 << " " << j << " " << j+1 << " ";
    }
    return 0;
  }
  for(int i = 0; i <= n; i += 4) {
    if (!((n - i) % 6)) {
      for(int j=1; j < i; j+=4) {
        std::cout << j+2 << " " << j+3 << " " << j << " " << j+1 << " ";
      }
      for(int j=i+1; j <= n; j+=6) {
        std::cout << j+3 << " " << j+4 << " " << j+5 << " " << j << " " << j+1 << " " << j+2 << " ";
      }
      return 0;
    }
  }
  // if (!(n%4)) {
  //   for(int i=1; i <= n; i+=4) {
  //     std::cout << i+2 << " " << i+3 << " " << i << " " << i+1 << " ";
  //   }
  // } else if (!(n%6)) {
  //   for(int i=1; i <= n; i+=6) {
  //     std::cout << i+3 << " " << i+4 << " " << i+5 << " " << i << " " << i+1 << " " << i+2 << " ";
  //   }
  // } else if (n % 6 == 4) {
  // }
  std::cout << -1;

  return 0;
}
