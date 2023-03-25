#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
std::string s;

char dfs(const int l, const int r) {
  if (l == r) {
    std::cout << (s[l] == '1' ? 'I' : 'B');
    return 1+(s[l] == '1');
  }
  const int mid = (l+r) >> 1;
  const char x = dfs(l, mid) | dfs(mid+1, r);
  if (x == 1) {
    std::cout << 'B';
  } else if (x == 2) {
    std::cout << 'I';
  } else {
    std::cout << "F";
  }
  return x;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::cin >> s;
  s = " " + s;
  dfs(1, 1<<n);

  return 0;
}
