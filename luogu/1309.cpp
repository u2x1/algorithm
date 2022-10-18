#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

struct Man { int score; int strength; int id; } mans[200005];
bool cmp(const int a, const int b) {
  if (mans[a].score == mans[b].score) { return mans[a].id < mans[b].id; }
  return mans[a].score > mans[b].score;
}

int main() {
  int n, r, q;
  scanf("%d%d%d", &n, &r, &q);
  n*=2;
  int all[200005];
  orep(i, 0, n) {
    scanf("%d", &mans[i].score);
    mans[i].id = all[i] = i;
  }
  orep(i, 0, n) {
    scanf("%d", &mans[i].strength);
  }
  std::sort(all, all+n, cmp);

  int wins[100005], loses[100005];
  while(r--) {
    int halfn = 0;
    for(int i = 0; i < n; i+=2) {
      int win=all[i], lose=all[i+1];
      if (mans[win].strength < mans[lose].strength) {
        std::swap(win, lose);
      }
      ++mans[win].score;
      wins[halfn] = win;
      loses[halfn] = lose;
      ++halfn;
    }
    int allCnt = 0;
    for(int l = 0, r = 0; allCnt < n; ) {
      if (l != halfn && (r == halfn || 
        cmp(wins[l], loses[r]))) {
        all[allCnt++] = wins[l++];
      } else { all[allCnt++] = loses[r++]; }
    }
  }

  printf("%d", all[q-1] + 1);

  return 0;
}
