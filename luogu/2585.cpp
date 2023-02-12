#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 5e5+5;
int dpMax[maxN][2], dpMin[maxN][2], cnt;
std::vector<int> son[maxN];

int read(int u=0) {
  char op; std::cin >> op;
  if (op == '1') {
    son[u].push_back(read(++cnt));
  } else if (op == '2') {
    son[u].push_back(read(++cnt));
    son[u].push_back(read(++cnt));
  }
  return u;
}

void initMax(int u=0) {
  if (!son[u].size()) { dpMax[u][1] = 1; return; }
  if (son[u].size() == 1) {
    const int v = son[u][0];
    initMax(v);
    dpMax[u][1] = 1 + dpMax[v][0];
    dpMax[u][0] = std::max(dpMax[v][0], dpMax[v][1]);
  } else {
    const int v1 = son[u][0], v2 = son[u][1];
    initMax(v1); initMax(v2);
    dpMax[u][1] = 1 + dpMax[v1][0] + dpMax[v2][0];
    dpMax[u][0] = std::max({dpMax[v1][1] + dpMax[v2][0]
                          , dpMax[v1][0] + dpMax[v2][1]});
  }
}

void initMin(int u=0) {
  if (!son[u].size()) { dpMin[u][1] = 1; return; }
  if (son[u].size() == 1) {
    const int v = son[u][0];
    initMin(v);
    dpMin[u][1] = 1 + dpMin[v][0];
    dpMin[u][0] = std::min(dpMin[v][0], dpMin[v][1]);
  } else {
    const int v1 = son[u][0], v2 = son[u][1];
    initMin(v1); initMin(v2);
    dpMin[u][1] = 1 + dpMin[v1][0] + dpMin[v2][0];
    dpMin[u][0] = std::min({dpMin[v1][1] + dpMin[v2][0]
                          , dpMin[v1][0] + dpMin[v2][1]});
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  read();
  initMax();
  initMin();
  std::cout << std::max(dpMax[0][1], dpMax[0][0]);
  std::cout << " ";
  std::cout << std::min(dpMin[0][1], dpMin[0][0]);
  

  return 0;
}
