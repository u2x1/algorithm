#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN][5];

int N, K;

struct Node { long long f[32]; } t[maxN*4];

Node combine(Node tl, Node tr) {
  Node ret;
  orep(k, 0, 1<<K) {
    ret.f[k] = std::max(tl.f[k], tr.f[k]);
  }
  return ret;
}

void pushup(int p) {
  t[p] = combine(t[p*2], t[p*2|1]);
}

void build(int cl = 1, int cr = N, int p = 1) {
  if (cl == cr) {
    orep(k, 0, 1<<K) {
      t[p].f[k] = 0;
      orep(i, 0, K) {
        t[p].f[k] += (((k>>i) & 1) ? 1 : -1) * arr[cl][i];
      }
    }
    return;
  }
  int m = (cl + cr) / 2;
  build(cl, m, p*2); build(m+1, cr, p*2+1);
  pushup(p);
}

void update(int pos, int cl = 1, int cr = N, int p = 1) {
  if (pos == cl && pos == cr) {
    orep(k, 0, 1<<K) {
      t[p].f[k] = 0;
      orep(i, 0, K) {
        t[p].f[k] += (((k>>i) & 1) ? 1 : -1) * arr[cl][i];
      }
    }
    return;
  }
  int m = (cl+cr) / 2;
  if (pos <= m) { update(pos, cl, m, p*2); }
  if (pos >  m) { update(pos, m+1, cr, p*2|1); }
  pushup(p);
}

Node ask(int l, int r, int cl = 1, int cr = N, int p = 1) {
  if (l <= cl && cr <= r) { return t[p]; }
  int m = (cl + cr) / 2;
  if (l <= m && r > m) { return combine(ask(l, r, cl, m, p*2), ask(l, r, m+1, cr, p*2|1)); }
  if (l <= m) { return ask(l, r, cl, m, p*2); }
  else { return ask(l, r, m+1, cr, p*2|1); }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> N >> K;
  orep(i, 1, N+1) { orep(j, 0, K) { std::cin >> arr[i][j]; } }
  build();
  int Q; std::cin >> Q;
  while(Q--) {
    int e; std::cin >> e;
    if (e == 1) {
      int I; std::cin >> I;
      orep(i, 0, K) { std::cin >> arr[I][i]; }
      update(I);
    } else {
      int L, R; std::cin >> L >> R;
      Node tmp = ask(L, R);
      long long ret = 0;
      orep(k, 0, (1<<(K-1))+1) {
        ret = std::max(ret, tmp.f[k]+tmp.f[((1<<K)-1)^k]);
      }
      std::cout << ret; NL;
    }
  }

  return 0;
}
