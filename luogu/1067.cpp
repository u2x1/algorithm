#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define REDIR        freopen("data.in", "r", stdin);

int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}

int main() {
  int n = read();

  int tmp;
  bool notFirst = 0;
  do {
    if (n <= 0) { break; }
    tmp = read();
    if (!tmp) { continue; }
    if (tmp > 0 && notFirst) { putchar('+'); }
    if (tmp == -1) { putchar('-'); }
    if (tmp != 1 && tmp != -1) {
      printf("%d", tmp);
    }
    putchar('x');
    if (n>1) { printf("^%d", n); }
    if (!notFirst) { notFirst = 1; }
  } while(--n);
  tmp = read();
  if (tmp) {
    if (tmp > 0 && notFirst) { putchar('+'); }
    printf("%d", tmp);
  }
  if (!notFirst && !tmp) {
    putchar('0');
  }
  return 0;
}
