#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN], pass[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  orep(i, 1, t+1) { std::cin >> arr[i]; pass[i] = i; }
  int cnt = 1;
  while(1) {
    orep(i, 1, t+1) {
      pass[i] = arr[pass[i]];
      if (pass[i] == i) { std::cout << cnt; return 0; }
    }
    ++cnt;
  }

  return 0;
}
