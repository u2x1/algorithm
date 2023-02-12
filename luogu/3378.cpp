#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e6+5;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  while(n--) {
    int op; std::cin >> op;
    if (op == 1) {
      int x; std::cin >> x;
      q.push(x);
    } else if (op == 2) {
      std::cout << q.top(); NL;
    } else {
      q.pop();
    }
  }

  return 0;
}
