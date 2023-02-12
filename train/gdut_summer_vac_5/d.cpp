#include <iostream>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, f; std::cin >> n >> f;
    orep(i, 1, n+1) { std::cin >> arr[i]; }

    int ret = 0;
    if(arr[f] > 0 && f > 1) { arr[f]=-arr[f]; ret = 1; }

    {
      long long sum = arr[f];
      std::priority_queue<long long> q;
      for(int i = f-1; i > 1; --i) {
        sum += arr[i];
        q.push(2*arr[i]);
        while (sum > 0) {
          sum -= q.top(); q.pop();
          ret++;
        }
      }
    }

    {
      long long sum = 0;
      std::priority_queue<long long> q;
      for(int i = f+1; i <= n; ++i) {
        sum += arr[i];
        q.push(-2*arr[i]);
        while (sum < 0) { 
          sum += q.top(); q.pop();
          ret++;
        }
      }
    }
    std::cout << ret; NL;
  }

  return 0;
}
