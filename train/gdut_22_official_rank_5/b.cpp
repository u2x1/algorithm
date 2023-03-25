#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
int q[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  if (n == 1) { std::cout << 0; return 0; }
  orep(i, 1, n+1) { std::cin >> arr[i]; }
  orep(i, 0, n) { std::cin >> q[i]; }
  int no = 1;
  drep(i, n-2, -1) {
    const int diff = abs(arr[q[i]]-arr[q[i+1]]);
    if (diff % m) {
      break;
    }
    no++;
  }
  std::cout << n - no;
  return 0;
}
