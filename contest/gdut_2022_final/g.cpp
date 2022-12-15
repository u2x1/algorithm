#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--){
    int n; scanf("%d", &n);
    if (n < 4) { printf("Mazige"); NL; continue; }
    if (!(n % 2)) { printf("Not Mazige"); NL; continue; }
  }
  return 0;
}
