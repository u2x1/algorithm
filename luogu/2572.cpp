#include <iostream>
#include <cstring>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e5+5;
bool arr[maxN];

struct Node { int c0, c1, l0, r0, v0, l1, r1, v1; } t[maxN*4];

int N;

int tg1[maxN*4], tg2[maxN*4];

Node combine(Node tl, Node tr) {
  Node ret = {
    tl.c0 + tr.c0, tl.c1 + tr.c1,
    tl.l0 + (!tl.c1) * tr.l0,
    tr.r0 + (!tr.c1) * tl.r0,
    std::max({tl.v0, tr.v0, tl.r0+tr.l0}),
    tl.l1 + (!tl.c0) * tr.l1,
    tr.r1 + (!tr.c0) * tl.r1,
    std::max({tl.v1, tr.v1, tl.r1+tr.l1}),
  };
  return ret;
}

void pushup(int p) {
  t[p] = combine(t[p*2], t[p*2+1]);
}

void mod(int p, int typ) {
  if (typ == 2) {
    tg2[p] = !tg2[p];
    std::swap(t[p].c0, t[p].c1);
    std::swap(t[p].v0, t[p].v1);
    std::swap(t[p].l0, t[p].l1); std::swap(t[p].r0, t[p].r1);
  } else {
    tg1[p] = typ; tg2[p] = 0;
    int len = t[p].c1+t[p].c0;
    t[p] = {
      len * (typ==0), len * (typ==1),
      len * (typ==0), len * (typ==0), len * (typ==0),
      len * (typ==1), len * (typ==1), len * (typ==1),
    };
  }

}

void pushdn(int p) {
  if (~tg1[p]) {
    mod(p*2, tg1[p]); mod(p*2+1, tg1[p]);
    tg1[p] = -1;
  }
  if (tg2[p]) {
    mod(p*2, 2); mod(p*2+1, 2);
    tg2[p] = 0;
  }
}

void build(int cl = 0, int cr = N-1, int p = 1) {
  if (cl == cr) {
    t[p] = {
      arr[cl] == 0, arr[cl] == 1,
      arr[cl] == 0, arr[cl] == 0, arr[cl] == 0,
      arr[cl] == 1, arr[cl] == 1, arr[cl] == 1,
    };
    return;
  }
  int m = (cl+cr) / 2;
  build(cl, m, p*2); build(m+1, cr, p*2+1);
  pushup(p);
}

void update(int l, int r, int typ, int cl = 0, int cr = N-1, int p = 1) {
  if (l <= cl && cr <= r) { 
    mod(p, typ); return;
  }
  pushdn(p);
  int m = (cl+cr) / 2;
  if (l <= m) { update(l, r, typ, cl, m, p*2); }
  if (r >  m) { update(l, r, typ, m+1, cr, p*2+1); }
  pushup(p);
}

Node ask(int l, int r, int cl = 0, int cr = N-1, int p = 1) {
  if (l <= cl && cr <= r) { return t[p]; }
  int m = (cl + cr) / 2;
  pushdn(p);
  if (l <= m && r > m) {
    return combine(ask(l, r, cl, m, p*2), ask(l, r, m+1, cr, p*2+1));
  }
  if (l <= m) { return ask(l, r, cl, m, p*2); }
  else { return ask(l, r, m+1, cr, p*2+1); }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int M; std::cin >> N >> M;
  orep(i, 0, N) { std::cin >> arr[i]; }
  build();
  memset(tg1, -1, sizeof(tg1));
  while(M--) {
    int e, a, b; std::cin >> e >> a >> b;
    if (e <= 2) { update(a, b, e); }
    else if (e == 3) {
      std::cout << ask(a, b).c1; NL;
    } else {
      std::cout << ask(a, b).v1; NL;
    }
  }

  return 0;
}
