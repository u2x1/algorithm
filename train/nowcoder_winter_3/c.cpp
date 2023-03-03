#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

void out(int j, int x) {
  if (x == 4) {
    std::cout << j+2 << " " << j+3 << " " << j << " " << j+1 << " ";
  } else if (x == 5) {
    std::cout << j+2 << " " << j+3 << " " << j+4 << " " << j << " " << j+1 << " ";
  } else if (x == 6) {
    std::cout << j+3 << " " << j+4 << " " << j+5 << " " << j << " " << j+1 << " " << j+2 << " ";
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  if (n == 6) {
    out(1, 6);
  } else if (n == 11) { 
    out(1, 6); out(7, 5);
  } else if (n == 4 || n == 5 || n == 8 || n == 10 || n >= 12){
    for(int i = 1; i < n;) {
      if ((n-i+1) % 4) {
        out(i, 5); i += 5;
      } else {
        out(i, 4); i += 4;
      }
    }
  } else {
    std::cout << -1;
  }
  return 0;
}
