#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e6;
int prefix[maxN];
int diff[maxN];

int main() {
  int n; scanf("%d", &n);
  int a, b, c;
  orep(i, 0, n) {
    scanf("%d%d%d" , &a, &b, &c);
    diff[std::max(0, a-b)] += c;
    diff[a+b+1] -= c;
  }
  prefix[0] = diff[0];
  orep(i, 1, maxN) {
    prefix[i] = prefix[i-1] + diff[i];
  }
  int max=-1, maxPos;
  for(int i = maxN; i > 0; --i) {
    if (prefix[i] >= max) {
      maxPos = i;
      max = prefix[i];
    }
  }
  printf("%d", maxPos);
  return 0;
}
