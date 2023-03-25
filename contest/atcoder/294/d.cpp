#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
int arr[maxN];
bool hit[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  int cur = 1;
  std::vector<int> q; int p = 0;
  orep(i, 0, m) {
    int op; std::cin >> op;
    if (op == 1) {
      q.push_back(cur++);
    } else if (op == 2) {
      int person; std::cin >> person;
      hit[person] = 1;
    } else {
      while(hit[q[p]]) { p++; }
      std::cout << q[p]; NL;
    }
  }

  return 0;
}
