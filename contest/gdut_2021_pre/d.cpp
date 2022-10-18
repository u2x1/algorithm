#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int final[1005], tmp[1005][11], cnt[1005];
bool passed[1005][11];

bool cmp(const int a, const int b) {
  if (cnt[a] != cnt[b]) { return cnt[a] > cnt[b]; }
  if (final[a] != final[b]) { return final[a] < final[b]; }
  return a < b;
}

int ids[1005];
int main() {
  int n, m; scanf("%d%d", &n, &m);
  orep(i, 0, m) {
    int a, b, c; char ch[4];
    scanf("%d%d%d%s", &a, &b, &c, ch);
    if (passed[a][c]) { continue; }
    if (ch[0] == 'a') {
      final[a] += tmp[a][c] + b;
      passed[a][c] = 1; cnt[a]++;
    }
    else { tmp[a][c] += 20; }
  }

  crep(i, 1, n) {
    ids[i] = i;
  }
  std::sort(ids+1, ids+n+1, cmp);
  crep(i, 1, n) {
    int id = ids[i];
    printf("%d %d %d", id, cnt[id], final[id]); NL;
  }

  return 0;
}