#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int n;
bool col[20], dia[100], revDia[100];
int totCnt, prtCnt;
int ans[20];

void dfs(const int depth) {
  if (depth == n) {
    totCnt++;
    if (prtCnt != 3) {
      orep(i, 0, depth) {
        printf("%d ", ans[i]+1);
      } NL;
      ++prtCnt;
    }
    return;
  }
  orep(i, 0, n) {
    int d = depth-i+n;
    int rd = depth+i;
    if (dia[d] || revDia[rd] || col[i]) { continue; }
    dia[d] = 1; col[i] = 1; revDia[rd] = 1; ans[depth] = i;
    dfs(depth+1);
    dia[d] = 0; col[i] = 0; revDia[rd] = 0;
  }
}

int main() {
  scanf("%d", &n);
  dfs(0);
  printf("%d", totCnt);
}