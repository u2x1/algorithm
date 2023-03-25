#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
int arr1[maxN];
int arr2[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 0, n) {
    std::cin >> arr1[i];
  }
  orep(i, 0, m) {
    std::cin >> arr2[i];
  }
  int cur = 0;
  int l = 0, r = 0;
  int cnt = 1;
  std::vector<int> out1, out2;
  while(l < n || r < m) {
    const int a = arr1[l], b = arr2[r];
    if (r == m || (l < n && a < b)) {
      out1.push_back(cnt);
      ++l;
    } else {
      out2.push_back(cnt);
      ++r;
    }
    ++cnt;
  }
  orep(i, 0, out1.size()) {
    std::cout << out1[i] << " ";
  } NL;
  orep(i, 0, out2.size()) {
    std::cout << out2[i] << " ";
  }

  return 0;
}
