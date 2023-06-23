#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
int fa[maxN];
using ui64 = unsigned long long;

int N, K;

int find(int x) {
  return x == fa[x] ? x : (fa[x] = find(fa[x]));
  // if (x == fa[x]) { return x; }
  // int rawfa = fa[x];
  // int newfa = find(rawfa);
  // fa[x] = newfa;
  // return newfa;
}

void merge(int faa, int x) {
  fa[find(x)] = find(faa);
}

bool valid(int x) { return x >= 0 && x < N; }

void dfs(int faa, int x) {
  merge(faa, x);
  if (valid(x-K) && find(x-K) != faa) { dfs(faa, x-K); }
  if (valid(x-K-1) && find(x-K-1) != faa) { dfs(faa, x-K-1); }
  if (valid(x+K) && find(x+K) != faa) { dfs(faa, x+K); }
  if (valid(x+K+1) && find(x+K+1) != faa) { dfs(faa, x+K+1); }
}

int X = 1333331;
ui64 mi[27];
ui64 h1[maxN];
ui64 h2[maxN];
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  mi[0] = 1;
  orep(i, 1, 27) { mi[i] = mi[i-1] * X; }
  int t; std::cin >> t;
  while(t--) {
    std::cin >> N >> K;
    std::string s, t; std::cin >> s >> t;
    orep(i, 0, N) {
      fa[i] = i;
      h1[i] = mi[s[i]-'a'];
      h2[i] = mi[t[i]-'a'];
    }
    orep(i, 0, N) { dfs(find(i), i); }
    // std::cout << N; NL;
    // orep(i, 0, N) { std::cout << find(i) << " "; } NL;
    orep(i, 0, N) {
      if (i == find(i)) { continue; }
      h1[find(i)] += h1[i];
      h2[find(i)] += h2[i];
      // if (find(i) != i) { continue; }
      // if (h1[i] == h2[i]) { continue; }
      // std::cout << "NO"; NL; goto fend;
    }
    orep(i, 0, N) {
      if (find(i) != i) { continue; }
      if (h1[i] == h2[i]) { continue; }
      //std::cout << h1[i] << " " << h2[i];  NL;
      std::cout << "NO"; NL; goto fend;
    }
    std::cout << "YES"; NL;
fend:;
  }

  return 0;
}
