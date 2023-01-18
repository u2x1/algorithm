#include <iostream>
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 5e3+5;
int arr[maxN];
int has[maxN];
int prod[maxN], prod_of_n[maxN][maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, p;
  std::cin >> n >> p;
  orep(i, 0, n) {
    std::cin >> arr[i];
    arr[i] %= p;
  }
  orep(i, 0, n) {
    orep(j, 0, i) {
      const int pd = (arr[i] * arr[j]) % p;
      prod[pd]++;
      prod_of_n[i][pd]++;
      prod_of_n[j][pd]++;
    }
  }
  orep(x, 0, p) {
    long long ret = 0;
    orep(i, 0, n) {
      int xxx = x - arr[i];
      while (xxx > p) { xxx-=p; }
      while (xxx < 0) { xxx+=p; }
      ret += prod[xxx]-prod_of_n[i][xxx];
    }
    std::cout << 2*ret << " ";
  }
  return 0;
}
