#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class SegTree {
  std::vector<T> tree, add, mul;
  std::vector<T> *arr;
  int n, root, n4, end;
  int mod;

  void mark(int cl, int cr, int p, T a, T m) {
    if (m != 1) {
      mul[p]  = (mul[p] * m);
      add[p]  = (add[p] * m);
      tree[p] = (tree[p] * m);
    }
    if (a) {
      add[p]  = (add[p] + a);
      tree[p] = (tree[p] + a * (cr - cl + 1));
    }
  }

  void pushdn(int cl, int cr, int p) {
    const int cm = cl + (cr - cl) / 2;
    const int l = p*2, r = l+1;
    if (cl != cr) {
      mark(cl  , cm, l, add[p], mul[p]);
      mark(cm+1, cr, r, add[p], mul[p]);
      mul[p] = 1;
      add[p] = 0;
    }
  }

  T range_sum(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) return tree[p];
    int m = cl + (cr - cl) / 2;
    T sum = 0;
    pushdn(cl, cr, p);
    if (l <= m) { sum = (sum + range_sum(l, r, cl, m, p * 2)) ; }
    if (r > m)  { sum = (sum + range_sum(l, r, m + 1, cr, p * 2 + 1)) ; }
    return sum;
  }

  void range_mod(int l, int r, T valA, T valM, int cl, int cr, int p) {
    if (l <= cl && cr <= r) {
      mark(cl, cr, p, valA, valM);
      return;
    }
    int m = cl + (cr - cl) / 2;
    pushdn(cl, cr, p);
    if (l <= m) { range_mod(l, r, valA, valM, cl, m, p * 2); }
    if (r > m)  { range_mod(l, r, valA, valM, m + 1, cr, p * 2 + 1); }
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

  void build(int s, int t, int p) {
    if (s == t) {
      tree[p] = (*arr)[s];
      return;
    }
    int m = s + (t - s) / 2;
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

 public:
  explicit SegTree<T>(std::vector<T> v) {
    n = v.size();
    n4 = n * 4;
    tree = std::vector<T>(n4, 0);
    add = std::vector<T>(n4, 0);
    mul = std::vector<T>(n4, 1);
    arr = &v;
    end = n - 1;
    root = 1;
    build(0, end, 1);
    arr = nullptr;
  }

  T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }
  void range_mod(int l, int r, int valA, int valM) { range_mod(l, r, valA, valM, 0, end, root); }
};

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 5e5+5;

int arr[105];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n; 
    orep(i, 0, n) {
      std::cin >> arr[i];
    }

    std::vector<int> v(n+1, 0);
    SegTree<int> seg(v);
    long long ret = 0;
    orep(i, 0, n) {
      ret += seg.range_sum(arr[i], n+1);
      seg.range_mod(arr[i], arr[i], 1, 1);
    }
    std::cout << ret; NL;
  }

  return 0;
}

