#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int dfs(int n, int ret, int x, int y) {
  if (n == 0 && (x||y)) { return 0; }
  if (n == 0 && (!x&&!y)) { return score; }
  return dfs(n-1, score)

}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

  return 0;
}
