#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
char arr[maxN];

int main() {
  int n; scanf("%d", &n);
  bool ctrl=0, ctrlc=0, ctrlv=0;
  while(n--) {
    scanf("%s", arr);
    if (strlen(arr) > 1) {
      if (arr[0] == 'C') {
        ctrl = 1;
      } else {
        ctrl = 0;
      }
    } else {
      if (ctrl) {
        if (arr[0] == 'C') {
          ctrlc = 1;
        } else if (ctrlc && arr[0] == 'V') {
          ctrlv = 1;
        }
      }
    }
  }
  printf(ctrlv ? "Yes" : "No");
  return 0;
}
