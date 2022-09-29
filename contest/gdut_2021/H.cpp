#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int cnts[100001], times[100001];
std::set<int> s;

inline int read() {
  int x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

long long calRst() {
  int rank = 1;
  long long rst=0;
  orep(it, s.begin(), s.end()) {
//    printf("(%d %d x%d) ", rank, *i, times[*i]);
    const int i = *it;
    rst += times[i] * ((rank) ^ i);
    rank += times[i];
  }
  return rst;
}

int main() {
  int n = read();
  std::vector<int> vs;
  orep(i, 0, n) {
    const int tmp = read();
    vs.push_back(tmp);
    if (cnts[tmp] && (--times[cnts[tmp]] == 0)) { s.erase(cnts[tmp]); }
    s.insert(++cnts[tmp]);
    ++times[cnts[tmp]];
  }
  int ops = read();
  while(ops--) {
    if (read() == 1) {
      const int x = read()-1, y = read();
      if (--times[cnts[vs[x]]] == 0) { s.erase(cnts[vs[x]]); }
      if (--cnts[vs[x]]) {
        times[cnts[vs[x]]]++;
        s.insert(cnts[vs[x]]);
      }

      if (--times[cnts[y]] == 0)   { s.erase(cnts[y]); }
      times[++cnts[y]]++;            s.insert(cnts[y]);

      vs[x] = y;
    } else {
      printf("%lld\n", calRst());
    }
  }
  return 0;
}
