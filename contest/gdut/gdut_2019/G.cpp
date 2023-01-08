#include <cstdio>
#include <cstring>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define REDIR        freopen("data.in", "r", stdin);

int a[13];

int trans(char c) {
  if (c >= '3' && c <= '9') {
    return c-'3';
  }
  switch(c) {
    case '0':
      return 7;
    case 'A':
      return 11;
    case '2':
      return 12;
    case 'J':
      return 8;
    case 'Q':
      return 9;
    case 'K':
      return 10;
    default:
      return -1;
  }
}

void write() {
  int pos;
  while((pos = trans(getchar())) == -1);
  ++a[pos];
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    memset(a, 0, sizeof(a));
    orep(i, 0, 17) { write(); }
    int out = 0;
    int dualCnt = 0, tripleCnt = 0;
    int twoCnt = 0, threeCnt = 0, bombCnt = 0;
    orep(i, 0, 13) {
      if (a[i] == 2) { ++dualCnt; ++twoCnt; }
      else if (a[i] == 3) { dualCnt += 3; ++tripleCnt; ++threeCnt; }
      else if (a[i] == 4) { dualCnt += 6; tripleCnt += 4; ++bombCnt; }
    }

    out += 17;
    out += dualCnt;
    out += bombCnt;
    out += tripleCnt * 14; out -= bombCnt*4;
    
    out += threeCnt * (twoCnt + bombCnt*6 + (threeCnt-1)*3);
    out += bombCnt * 4 * (twoCnt + threeCnt*3 + (bombCnt-1)*6);

    bool flag[13]; memset(flag, 1, sizeof(flag));
    orep(i, 0, 13) {
      if (!a[i]) {
        orep(j, std::max(0, i-4), i) {
          flag[j] = 0;
        }
      }
    }
    orep(i, 0, 9) {
      if (flag[i]) {
        int tmp = 1;
        orep(j, i, i+5) {
          tmp *= a[j];
        }
        out += tmp;
      }
    }
    printf("%d\n", out);
  }

  return 0;
}
