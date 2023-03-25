#include <iostream>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e6+5;
long long arr[maxN];
long long sum = 0ll;

std::vector<long long> l, r;

long long f(long long _x) {
  const long long x = sum - _x;
  long long ret = 0ll;
  for(unsigned long long i = 0ul, j = r.size()-1; i != l.size(); ++i) {
    // find l[i] + r[j] > x
    if (l[i] + r[j] <= x) { continue; }
    while(j != 0 && l[i] + r[j-1] > x) { --j; }
    ret += r.size() - j;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, k, m; std::cin >> n >> k >> m;
  orep(i, 1, 1+n) {
    std::cin >> arr[i];
    sum += arr[i];
  }

  l.push_back(0); r.push_back(0);
  orep(i, 1, k) {
    l.push_back(l[l.size()-1]+arr[i]);
  }
  for(int i = n, j = 1; i > k; --i, ++j) {
    r.push_back(r[r.size()-1]+arr[i]);
  }
  std::sort(l.begin(), l.end());
  std::sort(r.begin(), r.end());
  long long fl = -1e16, fr = 1e16;
  while (fl < fr-1) {
    const long long mid = fl + ((fr-fl) >> 1);
    // std::cout << " f(" << mid << "): " << f(mid); NL;
    if (f(mid) < m) { fl = mid; }
    else { fr = mid; }
  }
  std::cout << fl;

  return 0;
}
