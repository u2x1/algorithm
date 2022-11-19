#include <cstdio>
#include <map>
#include <algorithm>

#define cfor(i,a,b)    for(auto i=(a); i!=(b); ++i)
#define ffor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 2e5;
long long prefix[maxN], a[maxN];

bool cmp(std::pair<long long, int> a, std::pair<long long, int> b) { return a.second < b.second; }

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    ffor(i, 0, n, 1) { scanf("%lld", a+i); }
    prefix[0] = a[0]; ffor(i, 1, n, 1) { prefix[i] = prefix[i-1]+a[i]; }
    int ret = 0, pos = 0;
    for(; pos < n && a[pos]; ++pos) {
      ret += (prefix[pos] == 0);
    }
    std::map<long long, int> cnt;
    while(pos < n) {
      cnt.clear();
      ++cnt[prefix[pos++]];
      while(pos < n && a[pos]) {
        ++cnt[prefix[pos++]];
      }
      ret += (*std::max_element(cnt.cbegin(), cnt.cend(), cmp)).second;
    }
    printf("%d", ret); NL;
  }
  return 0;
}
