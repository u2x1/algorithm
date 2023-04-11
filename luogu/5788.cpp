#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
int ret[maxN];
int stk[maxN]; int cnt;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    std::cin >> arr[i];
    while(cnt && arr[stk[cnt-1]] < arr[i]) {
      ret[stk[cnt-1]] = i+1;
      cnt--;
    }
    stk[cnt++] = i;
  }
  orep(i, 0, n) { std::cout << ret[i] << " "; }


  return 0;
}
