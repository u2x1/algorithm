#include <cstdio>

int main() {
  int s, v;
  scanf("%d%d", &s, &v);
  const int offset = (s/v) + ((s%v)?1:0) + 10;
  const int all = 24*60-offset;
  const int hour = (all/60+8)%24, mins = all % 60;
  printf("%02d:%02d", hour, mins);

  return 0;
}
