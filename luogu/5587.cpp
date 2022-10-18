#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

std::vector<std::string> raw;

int main() {
  long long match=0;
  char tmp[100005];
  while(1) {
    int cnt=0; char c;
    while((c = getchar()) != '\n') {
      if (c == '<') {
        cnt = std::max(0, cnt-1);
      } else {
        tmp[cnt++] = c;
      }
    }
    tmp[cnt] = '\0';
    if (cnt == 3 
      && tmp[0] == 'E' && tmp[1] == 'O' && tmp[2] == 'F') { break; }
    raw.push_back(tmp);
  }
  int i = 0;
  while(1) {
    int cnt=0; char c;
    while((c = getchar()) != '\n') {
      if (c == '<') {
        cnt = std::max(0, cnt-1);
      } else {
        tmp[cnt++] = c;
      }
    }
    tmp[cnt] = '\0';
    if (cnt == 3 
      && tmp[0] == 'E' && tmp[1] == 'O' && tmp[2] == 'F') { break; }
    if (i < raw.size()) {
      orep(j, 0, raw[i].size()) {
        if (j == cnt) { break; }
        if (tmp[j] == raw[i][j]) { match++; }
      }
    }
    ++i;
  }
  int t;
  std::cin >> t;
  std::cout << (long long)(60.0*match/t + 0.5);

  return 0;
}