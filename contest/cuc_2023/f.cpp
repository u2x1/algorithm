#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
std::map<int, int> hash;

struct st { int id, x, y, realx; } ps[maxN];
bool cmp(st a, st b) { return a.x < b.x; }

int dpmax[maxN][30];
int dpmin[maxN][30];

int main() {
  memset(dpmin, 0x3f, sizeof(dpmin));
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<int> xs;
  orep(i, 0, n) {
    int x, y; std::cin >> x >> y;
    xs.emplace_back(x);
    ps[i].realx = x; ps[i].y = y; ps[i].id = i;
  }
  const int sz = std::unique(xs.begin(), xs.end()) - xs.begin();
  std::sort(xs.begin(), xs.begin()+sz);
  orep(i, 0, sz) { hash[xs[i]] = i+1; }
  orep(i, 0, n) {
    ps[i].x = hash[ps[i].realx];
    dpmax[ps[i].x][0] = std::max(ps[i].y, dpmax[ps[i].x][0]);
    dpmin[ps[i].x][0] = std::min(ps[i].y, dpmin[ps[i].x][0]);
  }

  orep(k, 1, 21) {
    for(int i = 1; i+(1<<k)-1 <= sz; ++i) {
      dpmax[i][k] = std::max(dpmax[i][k-1], dpmax[i+(1<<(k-1))][k-1]);
      dpmin[i][k] = std::min(dpmin[i][k-1], dpmin[i+(1<<(k-1))][k-1]);
    }
  }

  int q; std::cin >> q;
  while(q--) {
    int a, b; std::cin >> a >> b; a--; b--;
    if (ps[a].x >= ps[b].x) { std::cout << "0"; NL; continue; }
    int l = ps[a].x, r = ps[b].x;
    int k = log2(r-l+1);
    long long up = std::max(dpmax[l][k], dpmax[r-(1<<k)+1][k]);
    long long dn = std::min(dpmin[l][k], dpmin[r-(1<<k)+1][k]);
    std::cout << 1ll * (ps[b].realx - ps[a].realx) * (up - dn); NL;
  }


  return 0;
}
