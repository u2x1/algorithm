#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

template <typename T>
class SegTree {
  std::vector<T> tree, add, mul;
  std::vector<T> *arr;
  int n, root, n4, end;
  int mod;

  void mark(int cl, int cr, int p, T a, T m) {
    if (m != 1) {
      mul[p]  = (mul[p] * m) % mod;
      add[p]  = (add[p] * m) % mod;
      tree[p] = (tree[p] * m) % mod;
    }
    if (a) {
      add[p]  = (add[p] + a) % mod;
      tree[p] = (tree[p] + a * (cr - cl + 1)) % mod;
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

  void pushup(int p) {
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

  T range_sum(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) return tree[p];
    int m = cl + (cr - cl) / 2;
    T sum = 0;
    pushdn(cl, cr, p);
    if (l <= m) sum = (sum + range_sum(l, r, cl, m, p * 2)) % mod;
    if (r > m)  sum = (sum + range_sum(l, r, m + 1, cr, p * 2 + 1)) % mod;
    return sum;
  }

  void range_mod(int l, int r, T valA, T valM, int cl, int cr, int p) {
    if (l <= cl && cr <= r) {
      mark(cl, cr, p, valA, valM);
      return;
    }
    int m = cl + (cr - cl) / 2;
    pushdn(cl, cr, p);
    if (l <= m) range_mod(l, r, valA, valM, cl, m, p * 2);
    if (r > m) range_mod(l, r, valA, valM, m + 1, cr, p * 2 + 1);
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
  explicit SegTree<T>(std::vector<T> v, int m) {
    n = v.size();
    mod = m;
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


int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, q, p; std::cin >> n >> q >> p;

  std::vector<long long> arr(n+1);
  orep(i, 0, n) { std::cin >> arr[i]; }

  SegTree<long long> seg(arr, p);
  orep(i, 0, q) {
    long long op, l, r; std::cin >> op >> l >> r;
    --l; --r;
    if (op == 1) {
      long long k; std::cin >> k;
      seg.range_mod(l, r, 0, k);
    } else if (op == 2){
      long long k; std::cin >> k;
      seg.range_mod(l, r, k, 1);
    } else if (op == 3) {
      std::cout << seg.range_sum(l, r); NL;
    }
  }

  return 0;
}


