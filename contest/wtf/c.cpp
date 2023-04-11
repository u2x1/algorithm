#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  long long sum = 0ll;
  orep(i, 0, n) { std::cin >> arr[i]; sum += arr[i]; }
  int ret = 0;
  double avg = 1.0 * sum / n;
  orep(i, 0, n) {  if (arr[i] > avg) { ret++; } }
  std::cout << ret;

  return 0;
}
