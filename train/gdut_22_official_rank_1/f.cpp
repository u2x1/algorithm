#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    // int n; std::cin >> n;
    // int a; std::cin >> a;
    // int awin = 0;
    // orep(i, 1, n) {
    //   int tmp; std::cin >> tmp; 
    //   if (a != tmp) { awin = 1; }
    // }
    // if (n == 2 && !awin && a == 1) { std::cout << "Bob"; NL; }
    // else { std::cout << "Alice"; NL; }
    int n; std::cin >> n;
    int p = 1;
    for(int i = 1; i<=n; i++) {
      std::cin >> arr[i];
    }
    if (n == 2 && arr[1] == 1 && arr[2] == 1) { p = 0; }
    if (p) std::cout << "Alice\n";
    else std::cout << "Bob\n";
  }

  return 0;
}
