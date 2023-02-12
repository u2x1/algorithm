#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e6+5;
int d[maxN];

template <typename T>
class SegTree {
  std::vector<T> tree, mx;
  std::vector<T> *arr;
  int n, root, n4, end;

  T range_sum(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) return tree[p];
    int m = cl + (cr - cl) / 2;
    T sum = 0;
    if (l <= m) { sum = (sum + range_sum(l, r, cl, m, p * 2)); }
    if (r > m)  { sum = (sum + range_sum(l, r, m + 1, cr, p * 2 + 1)); }
    return sum;
  }

  void range_mod(int l, int r, int cl, int cr, int p) {
    if (mx[p] <= 2) { return; }
    if (l <= cl && cr <= r && cl == cr) {
      mx[p] = tree[p] = d[tree[p]];
      return;
    }
    int m = cl + (cr - cl) / 2;
    if (l <= m) { range_mod(l, r, cl, m, p * 2); }
    if (r > m)  { range_mod(l, r, m + 1, cr, p * 2 + 1); }
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
    mx[p] = std::max(mx[p * 2], mx[p * 2 + 1]);
  }

  void build(int s, int t, int p) {
    if (s == t) {
      mx[p] = tree[p] = (*arr)[s];
      return;
    }
    int m = s + (t - s) / 2;
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
    mx[p] = std::max(mx[p * 2], mx[p * 2 + 1]);
  }

 public:
  explicit SegTree<T>(std::vector<T> v) {
    n = v.size();
    n4 = n * 4;
    tree = std::vector<T>(n4, 0);
    mx = std::vector<T>(n4, 0);
    arr = &v;
    end = n - 1;
    root = 1;
    build(0, end, 1);
    arr = nullptr;
  }

  T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }
  void range_mod(int l, int r) { range_mod(l, r, 0, end, root); }
};

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 1, maxN) {
    for(int j=i; j < maxN; j+=i) {
      d[j]++;
    }
  }
  int n, m; std::cin >> n >> m;
  std::vector<long long> arr(n);
  orep(i, 0, n) { std::cin >> arr[i]; }
  SegTree<long long> seg(arr);
  orep(i, 0, m) {
    int op, x, y; std::cin >> op >> x >> y;
    --x; --y;
    if (op == 1) {
      seg.range_mod(x, y);
    } else {
      std::cout << seg.range_sum(x, y); NL;
    }
  }

  return 0;
}
