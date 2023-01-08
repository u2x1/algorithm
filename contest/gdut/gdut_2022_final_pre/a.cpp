#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;

bool isdigit(char c) {
  return c >= '0' && c <= '9';
}

char str[maxN];
int main() {
  scanf("%s", str);
  printf(str[1] == 'X' ? "AMD" : "Nvidia"); NL;
  int i = 0;
  while(!isdigit(str[i])) {
    ++i;
  }
  int id = 0;
  while(isdigit(str[i])) {
    id = id * 10 + str[i]-'0';
    ++i;
  }
  printf("%04d", id); NL;
  printf(str[i] != '\0' ? "Yes" : "No"); NL;
  return 0;
}
