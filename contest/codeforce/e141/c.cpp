#include <cstdio>
#include <algorithm>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

struct st { int id; int cost; };

bool operator<(const st a, const st b) { return a.cost == b.cost ? (a.id < b.id) : (a.cost < b.cost); }

const int maxN = 5e5+5;
st arr[maxN];
int raw[maxN];
int rank[maxN];
bool beat[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; long long m; scanf("%d%lld", &n, &m);
    orep(i, 0, n) { scanf("%d", &arr[i].cost); arr[i].id = i; rank[i] = i+1; raw[i] = arr[i].cost; beat[i] = 0; }
    std::sort(arr, arr+n);
    int got = 0;
    orep(i, 0, n) {
      if (beat[arr[i].id]) { continue; }
      if (got == n || arr[i].cost > m) {
        goto fend;
      } else if ((i+1 < n && arr[i].cost+arr[i+1].cost > m)
          && got + 1 < n && !beat[got+1] && raw[got+1] <= m) {
        m -= raw[got+1];
        beat[got+1] = 1;
        rank[got+1]--;
        ++got;
        --i; continue;
      } else {
        m -= arr[i].cost;
        beat[arr[i].id] = 1;
        rank[arr[i].id]--;
        ++got;
      }
    }
fend:;
    int* it = std::upper_bound(rank, rank+n, got);
    printf("%ld\n", n-(it-rank)+1);
  }

  return 0;
}
