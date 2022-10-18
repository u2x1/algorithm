#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

bool arr[1000001];
int cnt = 1;


int main() {
  int n; scanf("%d ", &n);
  int i = 0; while(i < n && getchar() == '0');
  if (i == n) { printf("0"); return 0; }
  orep(j, 1, n-i) {
    if(getchar() == '1') { arr[j] = 1; }
  }


  return 0;
}
