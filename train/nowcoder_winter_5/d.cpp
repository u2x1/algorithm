#include <iostream>
#include <algorithm>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];
struct st { int l, r; };
int l1[maxN], r1[maxN];
int l2[maxN], r2[maxN];
bool operator<(const st a, const st b) { return a.l > b.l; }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) { std::cin >> l1[i] >> r1[i]; }
  orep(i, 0, n) { std::cin >> l2[i] >> r2[i]; }
  std::priority_queue<st> aq, bq;
  int apos = 0, bpos = 0;
  orep(i, 0, n) {
    aq.push({l1[i], r1[i]});
    bq.push({l2[i], r2[i]});
    while(!aq.empty() && aq.top().l <= apos+1) {
      apos = std::max(apos, aq.top().r);
      aq.pop();
    }
    while(!bq.empty() && bq.top().l <= bpos+1) {
      bpos = std::max(bpos, bq.top().r);
      bq.pop();
    }
    if (apos == bpos)     { std::cout << "win_win!"; NL; std::cout << 0; NL; }
    else if (apos > bpos) { std::cout << "sa_win!"; NL; std::cout << apos - bpos; NL; }
    else if (apos < bpos) { std::cout << "ya_win!"; NL; std::cout << bpos - apos; NL; }
  }
  return 0;
}
