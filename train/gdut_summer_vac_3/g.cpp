#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
std::vector<int> arr[maxN];
int in[maxN];
bool vis[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n+1) {
    int tmp;
    while(1) {
      std::cin >> tmp;
      if (!tmp) { break; }
      arr[i].push_back(tmp);
      in[tmp]++;
    }
  }

  int out = n;
  while (out) {
    orep(i, 1, n+1) {
      if (!vis[i] && !in[i]) {
        out--;
        std::cout << i << " ";
        vis[i] = 1;
        orep(j, 0ul, arr[i].size()) {
          in[arr[i][j]]--;
        }
      }
    }
  }

  return 0;
}
