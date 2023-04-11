#include <iostream>
#include <set>
#include <queue>

#define orep(i, a, b) for(int i = (a); i < (b); ++i)
#define NL std::cout << '\n'

const int maxN = 5e5+5;
long long arr[maxN];
const long long INF = 1ll<<60;

struct st { long long val, idx; } t[maxN*4];
bool operator<(const st a, const st b) { return a.val < b.val; }

void pushup(const int p) {
  t[p] = std::min(t[p*2], t[p*2+1]);
}

void build(const int l, const int r, const int p) {
  if (l == r) { t[p] = { arr[l], l }; return; }
  const int m = (l+r)/2;
  build(l, m, p*2); build(m+1, r, p*2+1);
  pushup(p);
}

void mod(const int pos, const long long val, const int l, const int r, const int p) {
  if (l == pos && r == pos) {
    t[p] = { val, pos }; return;
  }
  int m = (l+r) / 2;
  if (pos <= m) { mod(pos, val, l, m, p*2); }
  else { mod(pos, val, m+1, r, p*2+1); }
  pushup(p);
}

int l[maxN], r[maxN];
int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  orep(i, 1, n+1) {
    std::cin >> arr[i]; l[i] = i-1; r[i] = i+1;
  }
  arr[0] = arr[n+1] = INF;
  build(0, n+1, 1);
  while(k--) {
    const int idx = t[1].idx;
    arr[l[idx]] += arr[idx];
    mod(l[idx], arr[l[idx]], 0, n+1, 1);
    arr[r[idx]] += arr[idx];
    mod(r[idx], arr[r[idx]], 0, n+1, 1);
    r[l[idx]] = r[idx]; l[r[idx]] = l[idx];
    mod(idx, INF, 0, n+1, 1);
    arr[idx] = INF;
  }
  orep(i, 1, n+1) {
    if (arr[i] >= INF) {
      continue;
    }
    std::cout << arr[i] << " ";
  }
  return 0;
}
