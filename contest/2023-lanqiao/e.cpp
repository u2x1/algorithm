#include <iostream>

#define orep(i, a, b) for(int i = (a); i < (b); ++i)
#define NL std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

void hNe(int x, int &head, int &end) {
  if (x < 0) {
    x = -x;
  }
  end = x % 10;
  while(x > 9) {
    x /= 10;
  }
  head = x;
}

int h[maxN], e[maxN];
int dp[10];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    int tmp; std::cin >> tmp;
    hNe(tmp, h[i], e[i]);
    dp[e[i]] = std::max(dp[e[i]], dp[h[i]]+1);
  }
  int ret = 0;
  orep(i, 0, 10) {
    ret = std::max(dp[i], ret);
  }
  
  std::cout << n - ret; 
	return 0;
}
