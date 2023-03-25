#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e6+5;
const int mod = 1e9+7;
int arr[maxN];
int p[10];

std::vector<int> state;

int m, n;

int get(const int x, const int pos) {  return x / p[pos] % 3; }

bool check(const int x) {
  orep(i, 1, m) {
    if (get(x, i-1) == get(x, i)) { return 0; }
  }
  return 1;
}

bool check(const int x, const int y) {
  orep(i, 0, m) {
    if (get(x, i) == get(y, i)) { return 0; }
  }
  return 1;
}

long long f[2][maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> m >> n;
  p[0] = 1;
  orep(i, 1, m+1) { p[i] = p[i-1] * 3;  }
  orep(i, 0, p[m]) {
    if (check(i)) { state.emplace_back(i); }
  }
  std::vector<std::vector<int>> avail(p[m]);
  for(auto s : state) {
    for(auto ss : state) {
      if (!check(s, ss)) { continue; }
      avail[s].emplace_back(ss);
    }
  }

  bool M = 0;
  for(auto s : state) { f[M][s] = 1; }

  orep(i, 1, n) {
    M = !M;
    for(auto s : state) {
      f[M][s] = 0;
      for(auto lst : avail[s]) {
         f[M][s] = (f[!M][lst] + f[M][s]) % mod;
      }
    }
  }

  long long ret = 0;
  for(auto s : state) {
    (ret += f[M][s]) %= mod;
  }

  std::cout << ret;

  return 0;
}
