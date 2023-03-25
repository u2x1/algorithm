#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
struct st { long long x, y; };
bool operator<(const st a, const st b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
st arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    orep(i, 0, n) {
      std::cin >> arr[i].x >> arr[i].y;
    }
    if (n < 5) { std::cout << "NO"; NL; continue; }
    long long x1 = arr[0].x, x2 = arr[1].x;
    long long y1 = arr[0].y, y2 = arr[1].y;
    int no = -1;
    std::vector<st> ret;
    orep(i, 2, n) {
      if ((y1-y2)*(x2-arr[i].x) != (x1-x2)*(y2-arr[i].y)) {
        std::cout << "YES"; NL;
        ret.push_back(arr[i]);
        no = i;
        break;
      }
    }
    if (~no) {
      int cnt = 0;
      orep(i, 0, n) {
        if (i == no || cnt == 4) { continue; }
        ret.push_back(arr[i]);
      }
      orep(i, 0ul, 5ul) {
        // std::cout << "for " << arr[i].x << " " << arr[i].y;  NL;
        std::set<st> s;
        bool flag = 1;
        orep(j, 0ul, 5ul) {
          if (i == j) { continue; }
          st one = {ret[j].x-ret[i].x, ret[j].y-ret[i].y};
          long long g = labs(std::__gcd(one.x, one.y));
          one.x /= g; one.y /= g;
          // std::cout << "for " << arr[j].x << " " << arr[j].y; 
          // std::cout << ": " << one.x << " " << one.y; NL;
          if (s.find(one) != s.end()) { flag = 0; }
          s.insert(one);
        }
        if (flag) {
          std::cout << ret[i].x << " " << ret[i].y; NL;
          orep(j, 0ul, 5ul) {
            if (i==j) { continue; }
            std::cout << ret[j].x << " " << ret[j].y; NL;
          }
          break;
        }
      }
    } else {
      std::cout << "NO"; NL;
    }
  }

  return 0;
}
