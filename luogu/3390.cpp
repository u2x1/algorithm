#include <iostream>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int mod = 1e9+7;
const int maxN = 1e2+5;
int arr[maxN];

int n;
struct Mat {
  long long val[maxN][maxN];
  Mat() { memset(val, 0, sizeof(val)); }
  void makeUnit() {
    orep(i, 0, n) { val[i][i] = 1; }
  }
};

Mat operator*(const Mat &a, const Mat &b) {
  Mat ret;
  orep(i, 0, n) {
    orep(j, 0, n) {
      orep(k, 0, n) {
        ret.val[i][j] += a.val[i][k]*b.val[k][j]%mod;
        ret.val[i][j] %= mod;
      }
    }
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long k; std::cin >> n >> k;
  Mat ret, a; ret.makeUnit();
  orep(i, 0, n) {
    orep(j, 0, n) {
      std::cin >> a.val[i][j];
    }
  }
  while(k) {
    if (k&1) { ret = (ret*a); }
    a = a*a; k>>=1;
  }
  orep(i, 0, n) {
    orep(j, 0, n) {
      std::cout << ret.val[i][j] << " ";
    } NL;
  }

  return 0;
}
