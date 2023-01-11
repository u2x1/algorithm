#include <cstdio>
#include <vector>
#include <cstring>
#include <map>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 2e5+5;
int arr[maxN];
int used[maxN]; int c;

inline int read() {
  int x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

int main() {
  int t; scanf("%d", &t); int tmp; 
  std::vector<std::vector<int>> v(maxN);
  while(t--) {
    int n = read();
    orep(i, 0, n) {
      int k = read();
      v[i].reserve(k+1); v[i][0] = k;
      orep(j, 0, k) {
        tmp = read();
        if (!arr[tmp]) { used[c++] = tmp; }
        arr[tmp]++; v[i][j+1] = tmp;
      }
    }
    orep(i, 0, n) {
      bool flag = 1;
      orep(j, 0, v[i][0]) {
        if (arr[v[i][j+1]] == 1) {
          flag = 0; break;
        }
      }
      if (flag) { printf("Yes"); goto fend; }
    }
    printf("No");
fend:;
    orep(i, 0, c) { arr[used[i]] = 0; }
    c=0;
    NL;
  }


  return 0;
}
