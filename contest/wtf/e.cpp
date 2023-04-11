#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

struct st { double val; int id; };
bool operator<(const st a, const st b) { return a.val < b.val; }
const double eps = 1e-15;

inline int sgn(double x) { return x<-eps ? -1 : x>eps; }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<st> v;
  std::vector<st> discardneg, discardpos;
  orep(i, 1, n+1) {
    double tmp; std::cin >> tmp;
    if (tmp >= 0 && tmp <= 1) { discardpos.push_back({tmp, i}); }
    else {v.push_back({tmp, i}); }
  }
  std::sort(v.begin(), v.end());
  std::vector<st> ret, neg;
  for(const st x : v) {
    if (sgn(x.val) < 0) { neg.push_back(x); }
    else { ret.push_back(x); }
  }
  if (neg.size() % 2) { discardneg.push_back(neg.back()); neg.pop_back(); }
  for(auto i = 0ul; i < neg.size(); i += 2) {
    if (sgn(neg[i].val*neg[i+1].val-1) > 0) {
      ret.emplace_back(neg[i]);
      ret.emplace_back(neg[i+1]);
    } else {
      discardneg.emplace_back(neg[i]);
      discardneg.emplace_back(neg[i+1]);
    }
  }
  if (ret.empty()) {
    std::sort(discardpos.rbegin(), discardpos.rend());
    std::sort(discardneg.begin(), discardneg.end());
    if (discardneg.size() > 1) {
      if (!discardpos.size() || sgn(discardpos[0].val - discardneg[0].val*discardneg[1].val) < 0) {
        ret = std::vector<st>({discardneg[0], discardneg[1]});
      } else {
        ret = std::vector<st>({discardpos[0]});
      }
    } else if (discardneg.size() == 1) {
      if (discardpos.size()) {
        ret = std::vector<st>({discardpos[0]});
      } else {
        ret = std::vector<st>({discardneg[0]});
      }
    } else {
      ret = std::vector<st>({discardpos[0]});
    }
  }
  std::vector<int> idx; for(const auto x : ret) { idx.emplace_back(x.id); }
  std::cout << idx.size(); NL;
  std::sort(idx.begin(), idx.end());
  for(const auto x : idx) { std::cout << x << " "; }

  return 0;
}
