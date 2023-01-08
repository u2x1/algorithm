#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i<(b); ++i)
#define NL           putchar(10);

const int maxN = 1e6+5;
int arr[maxN];
bool fixed[maxN];

int main() {
  int n, k, m; scanf("%d%d%d", &n, &k, &m);
  int sum = 0;
  orep(i, 0, m) {
    int x, yx; scanf("%d%d", &x, &yx);
    fixed[n+1-x] = 1;
    arr[n+1-x] = yx;
    sum = (sum+yx)%9;
  }
  
  int modPos = -1, rest = (k-sum+9)%9;
  orep(i, 1, n) {
    if (fixed[i]) { continue; }
    modPos = i;
    arr[i] = rest;
    break;
  }
  if (!fixed[n] && arr[n] == 0) {
    if (modPos == -1) { arr[n] = rest ? rest : 9; }
    else {
      arr[n] = 1;
      arr[modPos] = (arr[modPos]+8)%9;
    }
  }
  if (n==1 && k==0) { printf("0"); return 0; }
  for(int i = n; i > 0; --i) {
    putchar(arr[i]+'0');
  }
  return 0;
}
