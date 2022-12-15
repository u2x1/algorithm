#include <cstdio>
#include <queue>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];

int main() {
  std::priority_queue<int> q;
  int n, k; scanf("%d%d", &n, &k);
  orep(i, 0, n) {
    int tmp; scanf("%d", &tmp);
    if(q.size() >= k) {
      if (q.top() < tmp) {
        continue;
      }
      q.pop();
    }
    q.push(tmp);
  }
  int cnt = 0;
  while(q.size()) {
    arr[cnt++] = q.top(); q.pop();
  }
  for(int i = cnt-1, j = 0; j < k; --i, ++j) {
    printf("%d ", arr[i]);
  }
  return 0;
}

