#include <cstdio>
#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  char c;
  int a = 0; bool afalse = 0;
  while((c=getchar()) != ' ') {
    if (c <= '9' && c >= '0') {
      a = a*10+(c-'0');
    } else {
      afalse = 1;
    }
  }
  if (a < 1 || a > 1000) { afalse = 1; }
    
  int b = 0; bool bfalse = 0;
  while((c=getchar()) != EOF && c != '\n') {
    if (c <= '9' && c >= '0') {
      b = b*10+(c-'0');
    } else {
      bfalse = 1;
    }
  }
  if (b < 1 || b > 1000) { bfalse = 1; }
  

  if (!afalse && !bfalse) {
    std::cout << a << " + " << b << " = " << a+b; return 0;
  } else if (afalse && bfalse) {
    std::cout << "? + ? = ?";
  } else if (afalse) {
    std::cout << "? + " << b << " = ?"; return 0;
  } else if (bfalse) {
    std::cout << a << " + ? = ?";
  }



  return 0;
}
