#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 2e5+5;
int cnt;

int bucket[10];
int tmp[10];
bool check(int x) {
  int height = 0;
  memset(tmp, 0, sizeof(tmp));
  while(x) {
    if (!(x%10)) { return false; }
    height++;
    ++tmp[x%10];
    x/=10;
  }
  if (cnt < height) { return false; }
  orep(i, 0, 10) {
    if (bucket[i] < tmp[i]) { return false; }
  }
  if ((cnt > 3 && height == 3) || (cnt == height)) {
    return true;
  }
  return false;
}

int main() {
  char c;
  while((c=getchar()) != EOF && c >= '0' && c <= '9') {
    cnt++;
    ++bucket[c-'0'];
  }
  for(int i = 8; i <= 1000; i+=8) {
    if (check(i)) { printf("Yes"); return 0; }
  }
  printf("No"); return 0;
}
