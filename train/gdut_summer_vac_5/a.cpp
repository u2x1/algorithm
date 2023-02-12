#include <iostream>
#include <algorithm>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN], idx[maxN];
int lhs[maxN], rhs[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  while(1) {
    int n; std::cin >> n;
    if (!n) { return 0; }
    orep(i, 0, n) { std::cin >> arr[i]; }
    int cnt;

    cnt = 0;
    orep(i, 0, n) {
      while(cnt && arr[i] <= arr[idx[cnt-1]]) { --cnt; }
      lhs[i] = cnt ? idx[cnt-1]+1 : 0;
      idx[cnt++] = i;
    }

    cnt = 0;
    for(int i = n-1; i >= 0; --i) {
      while(cnt && arr[i] <= arr[idx[cnt-1]]) { --cnt; }
      rhs[i] = cnt ? idx[cnt-1]-1 : n-1;
      idx[cnt++] = i;
    }

    long long mx = -1;
    orep(i, 0, n) { mx = std::max(1ll*arr[i]*(rhs[i]-lhs[i]+1), mx) ; }
    std::cout << mx; NL;
  }
}
