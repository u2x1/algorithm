#include <iostream>
#include <algorithm>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];
struct st { bool op; int t, v; };
bool operator<(const st a, const st b) { return (a.t < b.t); }
st entity[maxN*2]; int cnt;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    std::cin >> arr[i];
  }
  orep(i, 0, n) {
    int a, b; std::cin >> a >> b;
    entity[cnt++] = {1,a,arr[i]};
    entity[cnt++] = {0,b,arr[i]};
  }
  std::sort(entity, entity+n*2);
  int cur = 0;
  int ret = 0;
  std::map<int, int> mp;
  orep(i, 0, n*2) {
    const st u = entity[i];
    if (u.op) {
      if (mp[u.v]++ == 0) { cur++; }
    } else {
      if (mp[u.v]-- == 1) { cur--; }
    }
    ret = std::max(cur, ret);
  }
  std::cout << ret;

  return 0;
}
