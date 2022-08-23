/* THIS FAILED */

#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define HIT          printf("entered <%s> at ln:%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define NL           putchar(10);
#define REDIR        freopen("../../data.in", "r", stdin);

bool cmp(const std::pair<int,int> a, const std::pair<int,int> b) {
  return a.second < b.second;
}

inline int read() {
  int x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

int calRst(std::map<int,int> mp) {
  std::vector<std::pair<int,int> > vs;
  orep(it, mp.begin(), mp.end()) {
    vs.push_back(*it);
  }
  sort(vs.begin(), vs.end(), cmp);
  int rank = 0, last = -1;
  int rst=0;
  orep(i, 0ul, vs.size()) {
    const int num = vs[i].second;
    if (num != last) { rank=i+1; last = num; }
    rst += (rank) ^ (num);
  }
  return rst;
}

int main() {
  int n = read();
  std::vector<int> vs;
  std::map<int, int> mp;
  orep(i, 0, n) {
    const int tmp = read();
    vs.push_back(tmp);
    auto it = mp.find(tmp);
    if (it == mp.end()) { mp[tmp] = 1; }
    else { ++(it->second); }
  }
  int ops = read();
  while(ops--) {
    if (read() == 1) {
      const int x = read()-1, y = read();
      const int tmp = vs[x];
      auto it = mp.find(tmp);
      if (it != mp.end()) { (it->second) = std::max(0, (it->second)-1);  }
      it = mp.find(y);
      if (it != mp.end()) { (it->second) = std::max(0, (it->second)+1); }
      else { mp[y] = 1; }
      vs[x] = y;
    } else {
      printf("%d\n", calRst(mp));
    }
  }

  return 0;
}
