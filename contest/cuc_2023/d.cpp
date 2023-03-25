#include <iostream>
#include <string>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
struct st { int p; int m; char q; } arr[maxN];
bool operator<(const st a, const st b) { return a.p < b.p; }

int c1[maxN], c2[maxN], c3[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  long long sum = 0;
  std::string s;
  orep(i, 0, n) {
    std::cin >> arr[i].p >> s >> arr[i].m;
    arr[i].q = s[0];
    sum += arr[i].m;
  }
  std::sort(arr, arr+n);
  int rk = 0;
  for(int i = 0; i < n;) {
    int cur = arr[i].p;
    while(i < n && arr[i].p == cur) {
//      std::cout << arr[i].p <<  " " << arr[i].q <<  " " << arr[i].m; NL;
      arr[i].p = rk;
      if (arr[i].q == '*') { c1[rk] += arr[i].m; }
      else if (arr[i].q == 'L') { c2[rk] += arr[i].m; }
      else if (arr[i].q == 'R') { c3[rk] += arr[i].m; }
      ++i;
    }
    ++rk;
  }
  long long ret = 0;
  orep(i, 0, rk) {
    int cur = 0;
    cur = std::max(cur, std::min(1, c1[i]));
    cur = std::max(cur, c2[i]);
    cur = std::max(cur, c3[i]);
    ret += cur;
  }
  // long long ret = 2ll<<60;
  // orep(i, 0, rk) {
  //   std::cout << c1[i] <<  " " << c2[i] <<  " " << c3[i]; NL;
  //   // if (c1[i] > 1) {
  //   //   ret = std::min(ret, sum - c1[i] + 2);
  //   // }
  //   if ((c1[i]||c3[i]) && c2[i]) {
  //     ret = std::min(ret, sum - (c1[i]+c3[i]) + 1);
  //     // ret = std::min(ret, sum - c1[i] + 1);
  //   }
  //   if ((c1[i]||c2[i]) && c3[i]) {
  //     ret = std::min(ret, sum - (c1[i]+c2[i]) + 1);
  //     // ret = std::min(ret, sum - c1[i] + 1);
  //   }
  //   // if (c1[i] && c2[i] && c3[i]) {
  //   //   ret = std::min(ret, sum - c2[i] + 1);
  //   //   ret = std::min(ret, sum - c3[i] + 1);
  //   // }
  //   // if (c2[i] && c3[i]) {
  //   //   ret = std::min(ret, sum - c2[i] + 1);
  //   //   ret = std::min(ret, sum - c3[i] + 1);
  //   // }
  //   // if (c1[i] > 1 || (c1[i] == 1 && (c2[i] || c3[i]))) {
  //   //   ret = std::min(ret, sum - (c1[i]+c2[i]+c3[i]) + 2);
  //   // } else if (c1[i] && c2[i]) {

  //   // }
  // }
  std::cout << (ret==sum ? -1 : ret+1);

  return 0;
}
