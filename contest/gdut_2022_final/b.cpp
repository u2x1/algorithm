#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 200;
int arr[maxN];

int main() {
  int t, k; scanf("%d%d", &t, &k);
  orep(i, 0, t) {
    int x,y; scanf("%d%d", &x, &y);
    ++arr[x]; --arr[y+1];
  }
  orep(i, 1, maxN) {
    arr[i] += arr[i-1];
  }
  int i = 0;

  int cnt = 0;
  while(i < 121) {
    while(i < 121 && arr[i] >= k) {
      ++i;
    }
    while(i < 121 && arr[i] < k) {
      ++i;
    }
    ++cnt;
  }
  printf("%d", cnt); NL;
  i=0;
  while(i < 121) {
    while(i < 121 && arr[i] >= k) {
      ++i;
    }
    int start = i;
    while(i < 121 && arr[i] < k) {
      ++i;
    }
    int end = i-1;
    printf("%d-%d", start, end); NL;
  }
  return 0;
}
