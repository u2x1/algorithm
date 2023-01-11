#include <cstdio>
#include <queue>
#include <algorithm>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 3e5+5;
long long arr[maxN], prefix[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n, m; scanf("%d%d", &n, &m);
    orep(i, 1, n+1) {
      scanf("%lld", arr+i);
      prefix[i] = prefix[i-1] + arr[i];
    }
    int cnt = 0;
    std::priority_queue<long long> qq;
    if (m > 1) {
      long long sum = 0;
      for(int i = m; i > 1; --i) {
        qq.push(2*arr[i]);
        sum += arr[i];
        if (sum > 0) {
          sum -= qq.top();
          ++cnt; qq.pop();
        }
      }
    }

    std::priority_queue<long long> q;
    long long sum = 0ll;
    orep(i, m+1, n+1) {
      q.push(-2*arr[i]);
      sum += arr[i];
      if (sum < 0) {
        sum += q.top();
        ++cnt; q.pop();
      }
    }
    printf("%d", cnt); NL;
  }

  return 0;
}
