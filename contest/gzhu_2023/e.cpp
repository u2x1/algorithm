#include <iostream>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
int extra[maxN];
int magic[maxN];
int rm[maxN], rmcnt;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, k; std::cin >> n >> m >> k;
  std::set<int> t;
  orep(i, 0, m) {
    int a, b; std::cin >> a >> b;
    if (a == 1) {
      t.insert(b);
      magic[b] = k;
    } else if (a == 2) {
      magic[b] = 0;
      t.erase(b);
    } else {
      std::cout << i+extra[b]; NL;
    }
    for(const auto x : t) {
      if (magic[x]) {
        extra[x]++;
        --magic[x];
        if (!magic[x]) { rm[rmcnt++] = x; }
      }
    }
    orep(j, 0, rmcnt) { t.erase(rm[j]); }
    rmcnt = 0;
  }
  return 0;
}
