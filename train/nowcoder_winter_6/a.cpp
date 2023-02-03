#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n; std::cin >> n;
  if (n <= 7) { std::cout << "very easy"; return 0; }
  if (n <= 233) { std::cout << "easy"; return 0; }
  if (n <= 10032) { std::cout << "medium"; return 0; }
  if (n <= 114514) { std::cout << "hard"; return 0; }
  if (n <= 1919810) { std::cout << "very hard"; return 0; }
  std::cout << "can not imagine"; return 0;
}
