#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 15;
std::string arr[maxN];
int dis[maxN][maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n,m; std::cin >> n >> m;
  orep(i, 0, n) { std::cin >> arr[i]; }
  orep(i, 0, n) {
    orep(j, 0, i) {
      orep(k, 0, m) {
        dis[i][j] += (arr[i][k] != arr[j][k]);
        dis[j][i] += (arr[i][k] != arr[j][k]);
      }
    }
  }
  std::vector<int> v;
  orep(i, 0, n) { v.emplace_back(i); }
  do{
    bool yes = 1;
    orep(i, 0, n-1) {
      if (dis[v[i]][v[i+1]] > 1) {
        yes = 0;
        break;
      }
    }
    if (yes) { std::cout << "Yes"; exit(0); }
  }
  while(std::next_permutation(v.begin(), v.end()));
  std::cout << "No";

  return 0;
}
