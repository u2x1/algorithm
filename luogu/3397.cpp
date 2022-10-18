#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int arr[1005][1005];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  crep(i, 0, n) {
    crep(j, 0, n) {
      arr[i][j] = 0;
    }
  }
  orep(i, 0, m) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
    arr[y1][x1] += 1;
    arr[y2+1][x2+1] += 1;
    arr[y1][x2+1] -= 1;
    arr[y2+1][x1] -= 1;
  }

  crep(i, 1, n) {
    crep(j, 1, n) {
      arr[i][j] += arr[i][j-1];
    }
  }

  crep(j, 1, n) {
    crep(i, 1, n) {
      arr[i][j] += arr[i-1][j];
    }
  }
  crep(i, 1, n) {
    crep(j, 1, n) {
      printf("%d ", arr[i][j]);
    }NL;
  }
}
