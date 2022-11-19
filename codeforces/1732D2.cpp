#include <cstdio>
#include <cmath>
#include <map>
#include <set>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

typedef unsigned long long ull;

inline ull read() {
  ull x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

const int maxN = 2e5;
std::map<ull, ull> check;
std::set<ull> removeSet;
char op[3];

int main() {
  int t; scanf("%d", &t);
  ull tmp;
  while(t--) {
    scanf("%s", op);
    tmp = read();
    if (op[0] == '+') {
      check[tmp] = 2;
      removeSet.erase(tmp);
    } else if (op[0] == '-') {
      check[tmp] = 0;
      removeSet.insert(tmp);
    } else {
      if (check[tmp] < 2) {
        printf("%llu", tmp); NL;
      } else {
        ull rst = tmp * check[tmp];
        while(1) {
          if (check[rst] < 2) {
            check[tmp] = rst / tmp;
            break;
          }
          rst += tmp;
        }
        for(auto it = removeSet.lower_bound(tmp); it!=removeSet.cend(); ++it) {
          if (*it >= rst) { break; }
          if (*it % tmp == 0) { rst = *it; break; }
        }
        printf("%llu", rst); NL;
      }
    }
  }
  return 0;
}
