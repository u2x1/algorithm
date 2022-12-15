#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i<(b); ++i)
#define NL           putchar(10);

const int maxN = 1e6+5;
int arr[305];
bool vis[maxN];
int cnt;

int main() {
  int n, w; scanf("%d%d", &n, &w);
  orep(i, 0, n) {
    scanf("%d", arr+i+1);
  }
  orep(i, 1, n+1) {
    if (arr[i] > w || vis[arr[i]]) { continue; }
    cnt += (vis[arr[i]] = 1);
    
  }
  orep(i, 1, n+1) {
    orep(j, 1, i) {
      orep(k, 0, j) {
        if (arr[i]+arr[j]+arr[k] > w || vis[arr[i]+arr[j]+arr[k]]) { continue; }
        cnt += (vis[arr[i]+arr[j]+arr[k]] = 1);
      }
    }
  }
  printf("%d", cnt);
  return 0;
}
