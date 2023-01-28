#include <vector>
#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int par[maxN];
int find(const int x) { return x==par[x] ? x : (par[x]=find(par[x])); }
void merge(const int x, const int y) { const int u = find(x), v = find(y); if (u!=v) { par[u] = v; } }

struct pt { int x,y,id; };
bool cmpx(const pt a, const pt b) { return a.x < b.x; }
bool cmpy(const pt a, const pt b) { return a.y < b.y; }
struct edge { int from, to, w; } edges[maxN];
bool operator<(const edge a, const edge b) { return a.w < b.w; }
int cnt;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<pt> pts;
  orep(i, 0, n) {
    int x, y; std::cin >> x >> y;
    pts.push_back({x,y,i});
    par[i] = i;
  }
  std::sort(pts.begin(), pts.end(), cmpx);
  for(int pos = 1; pos != n; ++pos) {
    edges[cnt].from = pts[pos-1].id;
    edges[cnt].to = pts[pos].id;
    edges[cnt].w = pts[pos].x-pts[pos-1].x;
    ++cnt;
  }
  std::sort(pts.begin(), pts.end(), cmpy);
  for(int pos = 1; pos != n; ++pos) {
    edges[cnt].from = pts[pos-1].id;
    edges[cnt].to = pts[pos].id;
    edges[cnt].w = pts[pos].y-pts[pos-1].y;
    ++cnt;
  }
  std::sort(edges, edges+cnt);
  long long rst = 0;
  orep(i, 0, cnt) {
    if (find(edges[i].from) == find(edges[i].to)) { continue; }
    merge(edges[i].from, edges[i].to);
    rst += edges[i].w;
  }
  std::cout << rst;
  
  return 0;
}
