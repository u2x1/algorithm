#include <cstdio>
#include <algorithm>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;

inline int read() {
  int x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

long long arr[2][maxN];

int main() {
  int t = read();
  while(t--) {
    memset(arr, 0, sizeof arr);
    long long ret = 0;
    int n = read(), m = read();
    bool mode = 0;
    orep(i, 0, n) {
      orep(j, 0, m) {
        arr[mode][j] = read();
      }
      std::sort(arr[mode], arr[mode]+m);
      int l = 0, r = 0;
      while(l < m && r < m) {
        if (arr[!mode][l] == arr[mode][r]) { ++l; ++r; ret++; }
        if (arr[!mode][l] < arr[mode][r]) { ++l; }
        if (arr[!mode][l] > arr[mode][r]) { ++r; }
      }
      mode = !mode;
    }
    printf("%lld\n", ret);
  }

  return 0;
}
