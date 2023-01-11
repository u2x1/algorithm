#include <iostream>
#include <queue>
#include <climits>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          '\n'

const int maxN = 2e2+5;
int arr[maxN];
long long mi[maxN][maxN], mx[maxN][maxN];

long long dfsMx(const int l, const int r) {
  if (mx[l][r]) { return mx[l][r]; }
  if (l == r) { return 0; }
  long long max = 0;
  orep(i, 0, r-l) {
    max = std::max(dfsMx(l, l+i) + dfsMx(l+i+1, r), max);
  }
  return mx[l][r] = max + arr[r]-arr[l-1];
}

long long dfsMi(const int l, const int r) {
  if (mi[l][r]) { return mi[l][r]; }
  if (l == r) { return 0; }
  long long min = 1ll<<62;
  orep(i, 0, r-l) {
    min = std::min(dfsMi(l, l+i) + dfsMi(l+i+1, r), min);
  }
  return mi[l][r] = min + arr[r]-arr[l-1];
}

int main() {
  int n; std::cin >> n;
  orep(i, 1, n+1) { std::cin >> arr[i]; arr[i+n] = arr[i]; arr[i] += arr[i-1]; }
  long long r1=1ll<<62, r2=0;
  orep(i, 1, n+1) {
    arr[i+n] += arr[i+n-1];
    r1 = std::min(dfsMi(i, i+n-1), r1);
    r2 = std::max(dfsMx(i, i+n-1), r2);
  }

  std::cout << r1 << NL;
  std::cout << r2 << NL;

  return 0;
}
