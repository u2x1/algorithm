#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN =4e6+5;
int arr[maxN];

std::string s;

bool t[maxN]; int tag[maxN];
int n;

void build(const int l, const int r, const int p) {
  if (l == r) { t[p] = s[l] == '1'; return; }
  const int m = (l+r) >> 1;
  build(l, m, p*2); build(m+1, r, p*2+1);
}

void pushdn(int p) {
  tag[p*2] = (tag[p]+tag[p*2]) % 2;
  tag[p*2+1] = (tag[p]+tag[p*2+1]) % 2;
  t[p*2] = (tag[p]+t[p*2]) % 2;
  t[p*2+1] = (tag[p]+t[p*2+1]) % 2;
  tag[p] = 0;
}

bool get(const int pos, const int p = 1, const int l = 0, const int r = n-1) {
  if (l == pos && pos == r) { return t[p]; }
  const int m = (l+r) >> 1;
  pushdn(p);
  if (pos <= m) { return get(pos, p*2, l, m); }
  else { return get(pos, p*2+1, m+1, r); }
}

void mod(int l, int r, int cl = 0, int cr = n-1, int p = 1) {
  if (l <= cl && cr <= r) {
    if (cl == cr) { t[p] = !t[p]; return; }
    else { tag[p]++; return; }
  }
  pushdn(p);
  const int m = (cl+cr) >> 1;
  if (l <= m) { mod(l, r, cl, m, p*2); }
  if (r > m) { mod(l, r, m+1, cr, p*2+1); }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int q; std::cin >> n >> q;
  int a1, a2, b1, b2; std::cin >> a1 >> a2 >> b1 >> b2;
  std::cin >> s;
  build(0, n-1, 1);
  while(q--) {
    int a, b, c; std::cin >> a >> b >> c;
    if (a == 1) {
      mod(b-1, c-1);
    } else {
      std::cout << (get(c-1) ? "Magical Splash Flare" : "HoloPsychon"); NL;
    }
    // orep(i, 0, n) { std::cout << get(i); } NL;
  }

  return 0;
}
