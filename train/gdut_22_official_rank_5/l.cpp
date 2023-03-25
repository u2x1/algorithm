#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  int sum = 1000; int a = 1001;
  orep(i, 1, n+1) {
    std::cout << sum << " ";
    arr[i] = sum+a;
    sum += a;
    a+=1;
  }

  return 0;
}
