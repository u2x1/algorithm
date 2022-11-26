#include <cstdio>
#include <map>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 1e5;

int map[255];
std::map<int, int> cnt;

int main() {
  map['A'] = map['B'] = map['C'] = 2;
  map['D'] = map['E'] = map['F'] = 3;
  map['G'] = map['H'] = map['I'] = 4;
  map['J'] = map['K'] = map['L'] = 5;
  map['M'] = map['N'] = map['O'] = 6;
  map['P'] = map['R'] = map['S'] = 7;
  map['T'] = map['U'] = map['V'] = 8;
  map['W'] = map['X'] = map['Y'] = 9;
  cfor(i, 0, 10, 1) { map['0'+i] = i; }

  int t;
  while(scanf("%d ", &t) == 1) {
    while(t--) {
      int rst = 0; char c;
      while((c=getchar()) != '\n' && c != EOF) {
        if (c == '-' || c == '\r') { continue; }
        rst = rst * 10 + map[c];
      }
      ++cnt[rst];
    }
    bool flag = 1;
    for(auto it = cnt.cbegin(); it != cnt.cend(); ++it) {
      if (it->second < 2) { continue; }
      printf("%03d-%04d %d", it->first/10000, it->first%10000, it->second); NL;
      flag = 0;
    }
    printf(flag ? "No duplicates.\n" : "");
    cnt.clear();
  }
  return 0;
}
