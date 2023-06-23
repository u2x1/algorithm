#include <iostream>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int fa[maxN], arr[maxN], bit[maxN], hs[maxN];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

std::map<int, unsigned long long> idx;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, a, b; std::cin >> n >> a >> b;
  orep(i, 0, n) { std::cin >> arr[i]; idx[arr[i]] = i; fa[i] = i; hs[i] = 0b11; }
  orep(i, 0, n) {
    if (idx.find(a-arr[i]) != idx.end()) { fa[find(idx[a-arr[i]])] = find(i); bit[i] |= 0b01; }
    if (idx.find(b-arr[i]) != idx.end()) { fa[find(idx[b-arr[i]])] = find(i); bit[i] |= 0b10; }
  }
  orep(i, 0, n) {
    hs[find(i)] &= bit[i];
    if (!hs[find(i)]) { std::cout << "NO"; return 0; }
  }
  std::cout << "YES"; NL;
  orep(i, 0, n) {
    std::cout << !(hs[find(i)]&1) << " ";
  }

  return 0;
}
