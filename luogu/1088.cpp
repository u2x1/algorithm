#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];
bool vis[maxN];

int main() {
  int n, m; scanf("%d%d", &n, &m);
  orep(i, 0, n) {
    int tmp; scanf("%d", &tmp);
    orep(j, 1, n+1) {
      if (j==tmp) { break; }
      arr[i] += !vis[j];
    }
    vis[tmp] = 1;
  }
  arr[n-1] += m;
  long long ret = 0;
  orep(i, 0, n-1) {
    const int pos = n-i-1;
    const int mod = i+1;
    arr[pos-1] += arr[pos] / mod;
    arr[pos] %= mod;
  }
  orep(i, 0, n) { vis[i]=0; }
  orep(i, 0, n) {
    orep(j, 0, n) {
      if (vis[j]) {continue;}
      if (arr[i]) {--arr[i];}
      else {printf("%d ", j+1);vis[j]=1;break;}
    }
  }
  return 0;
}
