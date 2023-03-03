#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int prevdis[maxN];
int prevtim[maxN];
bool vis[maxN];

struct edge { int to, len, t; };
long long dis[maxN];
long long ttt[maxN];

struct node1 { int v;};
bool operator<(const node1 a, const node1 b) { return dis[a.v] > dis[b.v]; }
struct node2 { int v;};
bool operator<(const node2 a, const node2 b) { return ttt[a.v] > ttt[b.v]; }


int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<edge>> son(n+1);
  orep(i, 0, m) {
    int v1, v2, oneway, len, t; std::cin >> v1 >> v2 >> oneway >> len >> t;
    son[v1].push_back({v2, len, t});
    if (!oneway) {
      son[v2].push_back({v1, len, t});
    }
  }
  int s, t; std::cin >> s >> t;
  memset(dis, 63, sizeof(dis));
  memset(ttt, 63, sizeof(ttt));



  ttt[s] = dis[s] = 0;

  std::priority_queue<node2> q2;
  q2.push({s});
  while(!q2.empty()) {
    const int vv = q2.top().v; q2.pop();
    if (vis[vv]) { continue; } vis[vv] = 1;
    orep(i, 0ul, son[vv].size()) {
      const int to = son[vv][i].to, t = son[vv][i].t;
      if (ttt[to] > ttt[vv] + t) {
        ttt[to] = ttt[vv] + t;
        q2.push({to});
        prevtim[to] = vv;
      }
    }
  }

  std::vector<int> out1;
  out1.push_back(t);
  for(int u = t; u != s; ) {
    u = prevtim[u];
    out1.push_back(u);
  }

  memset(vis, 0, sizeof(vis));
  std::priority_queue<node1> q1;
  q1.push({s});
  while(!q1.empty()) {
    const int vv = q1.top().v; q1.pop();
    if (vis[vv]) { continue; } vis[vv] = 1;
    orep(i, 0ul, son[vv].size()) {
      const int to = son[vv][i].to, len = son[vv][i].len;
      if (dis[to] > dis[vv] + len) {
        dis[to] = dis[vv] + len;
        q1.push({to});
        prevdis[to] = vv;
      }
    }
  }

  std::vector<int> out;
  out.push_back(t);
  for(int u = t; u != s; ) {
    u = prevdis[u];
    out.push_back(u);
  }

  if (out == out1) {
    std::cout << "Time = " << ttt[t] << "; Distance = " << dis[t] << ": ";
    orep(i, 0, out.size()) {
      std::cout << out[i];
      if (i != out.size()-1) {
        std::cout << " => ";
      }
    }
  } else {
    std::cout << "Time = " << ttt[t] << ": ";
    for(int i = out1.size() - 1; i > -1; --i) {
      std::cout << out1[i];
      if (i != 0) {
        std::cout << " => ";
      }
    }
    NL;
    std::cout << "Distance = " << dis[t] << ": ";
    for(int i = out.size() - 1; i > -1; --i) {
      std::cout << out[i];
      if (i != 0) {
        std::cout << " => ";
      }
    }
  }



  return 0;
}
