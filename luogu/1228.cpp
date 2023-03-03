#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];
int x, y;

struct st { int sx, sy, tx, ty; };

void out(const int _size, const st area, const int shape) {
  const int size = (1 << _size);
  if (size == 4) {
    switch(shape) {
      // case 1:
      //   std::cout << tx << " " << ty; NL; return;
      // case 2:
      //   std::cout << tx << " " << sy; NL; return;
      // case 3:
      //   std::cout << sx << " " << ty; NL; return;
      // case 4:
      //   std::cout << sx << " " << sy; NL; return;
    }
  } else {
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int k; std::cin >> k;
  std::cin >> x >> y;
  const int pos = (1<<(k-1));

  int s;
  if (x > pos && y > pos) { s = 4; }
  else if (x > pos) { s = 3; }
  else if (y > pos) { s = 2; }
  else { s = 1; }

  const int t = (1<<k);
  out(k, {1,1,t,t}, s);

  return 0;
}
