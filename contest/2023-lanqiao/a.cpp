#include <iostream>
#include <vector>

#define orep(i, a, b) for(int i = (a); i < (b); ++i)
#define NL std::cout << '\n'

bool vis[100000];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::vector<int> arr({2,0,0,3,7,9,2,7,0,5,8,8,5,7,0,9,9,1,9,4,4,6,8,6,3,3,8,5,1,6,3,4,6,7,0,7,8,2,7,6,8,9,5,6,5,6,1,4,0,1,0,0,9,4,8,0,9,1,2,8,5,0,2,5,3,3});
  const int n = arr.size();
  int ret = 0;
  orep(a, 0, n) orep(b, a+1, n) orep(c, b+1, n) orep(d, c+1, n)
  orep(e, d+1, n) orep(f, e+1, n) orep(g, f+1, n) orep(h, g+1, n) {
    if (arr[a] == 2 && arr[b] == 0 && arr[c] == 2 && arr[d] == 3) {
      const int me = arr[e] * 1000 + arr[f]*100 + arr[g]*10 + arr[h];
      if ((arr[e]*10 + arr[f]) > 0 && (arr[e]*10 + arr[f]) < 13
         && arr[g]*10 + arr[h] > 0 && arr[g]*10 + arr[h] < 32 && !vis[me]) {
        // std::cout << me; NL;
        if (arr[g]*10 + arr[h] >= 28 && arr[g]*10 + arr[h] < 32) {
          std::cout << me; NL;
        }
        ret++;
        vis[me] = 1;
      }
    }
  }
  std::cout << ret;
	return 0;
}
