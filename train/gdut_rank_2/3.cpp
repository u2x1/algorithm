#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int cnt;
int vis[10];
int arr[11];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s;
  std::cin >> s;
  orep(i, 0ul, s.size()) {
    if (vis[s[i]-'0']) { continue; }
    vis[s[i]-'0'] = 1;
  }
  std::cout << "int[] arr = new int[]{";
  bool notfst = 0;
  for(int i = 9; i > -1; --i) {
    if (vis[i]) {
      if (notfst) { std::cout << ","; }
      arr[cnt++] = i;
      std::cout << i;
      notfst = 1;
    }
  }
  std::cout << "};"; NL;
  std::cout << "int[] index = new int[]{";
  notfst = 0;
  orep(i, 0ul, s.size()) {
    int c  = s[i] - '0';
    orep(k, 0, cnt) {
      if (c == arr[k]) {
        if (notfst) { std::cout << ","; }
        std::cout << k;
        notfst = 1;
        break;
      }
    }
  }
  std::cout << "};";

  return 0;
}
