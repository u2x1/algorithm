#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)

struct Res { unsigned int id; std::string content; unsigned int time; };
bool operator<(const Res a, const Res b) { return a.time < b.time; }

int main() {
  std::ios::sync_with_stdio(0);
  std::vector<Res> rs;
  int n; std::cin >> n;
  std::string tmp;
  crep(i, 1, n) {
    std::cin >> tmp;
    bool exit=0;
    unsigned int t; std::cin >> t;
    orep(j, rs.begin(), rs.end()) {
      if (j->content == tmp) {
        if (j->time < t) { rs.erase(j); exit = 0; break; }
        else { exit=1; break; }
      }
    }
    if (exit) { continue; }
    Res r; r.id = i; r.content = tmp; r.time = t;
    rs.push_back(r);
  }
  std::sort(rs.begin(), rs.end());
  orep(i, 0, rs.size()) {
    printf("%d\n", rs[i].id);
  }
  
  return 0;
}
