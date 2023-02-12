#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];
struct st { int idx; };

bool cmp(const int a, const int b) { return arr[a] < arr[b]; }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, t; std::cin >> n >> t;
  orep(i, 0, n) {
    std::cin >> arr[i];
    indice[i] = i;
  }
  std::sort(indice, indice+n, cmp);

  return 0;
}
