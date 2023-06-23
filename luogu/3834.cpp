#include <iostream>
#include <vector>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
std::vector<int> v;

int N, M;
int cnt;

struct Node { int val, l, r; } t[maxN*4*20];

int build(int l = 1, int r = v.size()) {
  int u = ++cnt;
  if (l == r) { return u; }
  int m = (l + r) / 2;
  t[u] = { 0, build(l, m), build(m+1, r) };
  return u;
}

void pushup(int p) { t[p].val = t[t[p].l].val + t[t[p].r].val; }

int update(int pos, int p, int cl = 1, int cr = v.size()) {
  int u = ++cnt;
  t[u] = t[p];
  if (cl == pos && cr == pos) { ++t[u].val; return u; }
  int m = (cl + cr) / 2;
  if (pos <= m) { t[u].l = update(pos, t[p].l, cl, m); }
  else { t[u].r = update(pos, t[p].r, m+1, cr); }
  pushup(u);
  return u;
}

int ask(int k, int uu, int vv, int cl = 1, int cr = v.size()) {
  if (cl == cr) { return cl; }
  int m = cl+ ((cr-cl) >> 1);
  int lcnt = t[t[uu].l].val - t[t[vv].l].val;
  if (lcnt >= k) { return ask(k, t[uu].l, t[vv].l, cl, m); }
  else { return ask(k - lcnt, t[uu].r, t[vv].r, m+1, cr); }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> N >> M;
  orep(i, 0, N) { std::cin >> arr[i]; }
  std::set<int> st(arr, arr+N);
  v = std::vector<int>(st.begin(), st.end());
  build();
  std::vector<int> root(N+1);
  root[0] = 1;
  const auto fidx = [&](int x) { return std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1; };
  orep(i, 0, N) {
    root[i+1] = update(fidx(arr[i]), root[i]);
  }
  orep(i, 0, M) { 
    int l, r, k; std::cin >> l >> r >> k;
    std::cout << v[ask(k, root[r], root[l-1])-1]; NL;
  }

  return 0;
}
