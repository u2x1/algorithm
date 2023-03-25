#include <iostream>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
const int mod = 1e9+7;
int arr[maxN];

const int n = 3;
struct Mat { int x,y; long long val[n][n]; };
const Mat tran = { 3, 3, {1,1,1, 0,1,1, 1,1,2} };
const Mat base = { 1, 3, {1,1,1} };

Mat operator*(const Mat &a, const Mat &b) {
  Mat ret = { 3, 3, {0,0,0, 0,0,0, 0,0,0} };
  orep(i, 0, a.x) {
    orep(j, 0, b.y) {
      orep(k, 0, a.y) {
        ret.val[i][j] += a.val[i][k] * b.val[k][j] % mod;
        ret.val[i][j] %= mod;
      }
    }
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int x; std::cin >> x;
    x--;
    int k = x / 3;
    Mat ret = base, a = tran;
    while(k) {
      if(k&1) { ret = (ret*a); }
      k >>= 1; a = (a*a);
    }
    std::cout << ret.val[0][x%3]; NL;
  }

  return 0;
}
