#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e2+5;
int arr[maxN];
int n, k;
std::string START, END;
std::string name[maxN];
std::map<std::string, int> mp;

struct st { int to, cost; };
std::vector<st> son[maxN];

int enemy[maxN];
int dis[maxN], pass[maxN], estim[maxN], prev[maxN], cnt[maxN];
bool vis[maxN];
struct node { int u; };
bool operator<(const node a, const node b) { return dis[a.u] > dis[b.u]; }
void dij() {
  memset(dis, 63, sizeof(dis));
  std::priority_queue<node> q;
  dis[0] = 0; cnt[0] = 1;
  q.push({0});
  while(!q.empty()) {
    const int v = q.top().u; q.pop();
    if (vis[v]) { continue; } vis[v] = 1;
    orep(it, son[v].cbegin(), son[v].cend()) {
      const int u = it->to, w = it->cost;
      if (dis[u] > dis[v] + w) {
        dis[u] = dis[v] + w;
        prev[u] = v;
        q.push({u});
        estim[u] = estim[v]+enemy[u];
        pass[u] = pass[v]+1;
        cnt[u] = cnt[v];
      } else if (dis[u] == dis[v] + w) {
        cnt[u] += cnt[v];
        if (pass[v]+1 > pass[u]) {
          pass[u] = pass[v] + 1;
          estim[u] = estim[v]+enemy[u];
          prev[u] = v;
        } else if (pass[v]+1 == pass[u]) {
          if (estim[v]+enemy[u] > estim[u]) {
            estim[u] = estim[v]+enemy[u];
            prev[u] = v;
          }
        }
      }
    }
  }
}

void out(int u) {
  if (u == 0) { std::cout << START; return; }
  out(prev[u]);
  std::cout << "->" << name[u];
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> k >> START >> END;
  mp[START] = 0;
  std::string s; int tmp;
  orep(i, 1, n) {
    std::cin >> s >> tmp; mp[s] = i;
    name[i] = s;
    enemy[i] = tmp;
  }
  std::string aa, bb; int cost;
  orep(i, 0, k) {
    std::cin >> aa >> bb >> cost;
    const int a = mp[aa], b = mp[bb];
    son[a].push_back({b, cost});
    son[b].push_back({a, cost});
  }
  dij();
  out(mp[END]); NL;
  std::cout << cnt[mp[END]] << " " << dis[mp[END]] << " " << estim[mp[END]];
  // orep(i, 0, n) {
  //   std::cout << dis[i]; NL;
  // }

  return 0;
}
