#include <iostream>
#include <set>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
long long arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  long long a = 1;
  orep(i, 0, n) {
    std::cout << a << " ";
//    arr[i] = a;
    a <<= 1;
  }
//  int cnt = 0;
//  std::set<long long> wtf;
//  orep(i, 0, (1<<n)) {
//    int cc = i;
//    long long sum = 0;
//    for(int j = 0; j < n; ++j) {
// //     std::cout << ((cc>>j)&1);
//      if((cc >> j)&1){
//        sum += arr[j]; }
//    }
//    wtf.insert(sum);
//    ++cnt;
//  }
//  std::cout << wtf.size() << " " << cnt; NL;

  return 0;
}
