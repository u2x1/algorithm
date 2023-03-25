#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
int c[5], d[5];
long long f[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 0, 4) { std::cin >> c[i]; }
  int n; std::cin >> n; 
  f[0] = 1;
  orep(i, 0, 4) {
    orep(j, c[i], maxN) { f[j] += f[j-c[i]]; }
  }
  while(n--) {
    orep(i, 0, 4) { std::cin >> d[i]; }
    int s; std::cin >> s;
    long long ret = f[s];
    for(int i = 1; i < (1<<4); ++i) {
      long long cur = s; bool odd = 0;
      for(int j = 0; j < 4; ++j) {
        if ((i>>j) & 1) { cur -= c[j]*(d[j]+1); odd = !odd; }
      }
      if (cur >= 0) { ret += odd ? -f[cur] : f[cur]; }
    }
    std::cout << ret; NL;
  }

  return 0;
}
