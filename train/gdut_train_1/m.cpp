#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
struct st { int x, y; } arr[maxN];

st vec(st a, st b) {
  return { b.x-a.x, b.y-a.y };
}

bool cmp(st v1, st v2) {
  return 1;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n+1) {
    std::cin >> arr[i].x >> arr[i].y;
  }
  arr[0].x = arr[n].x;
  arr[0].y = arr[n].y;
  arr[n+1].x = arr[1].x;
  arr[n+1].x = arr[1].x;
  bool flag = 0;
  orep(i, 1, n+1) {
    const st v1 = arr[i-1], v2 = arr[i], v3 = arr[i+1];
    const st vec1 = vec(v1, v2), vec2 = vec(v3, v2);
    if (v1.y < v2.y) { continue; }
  }

  return 0;
}
