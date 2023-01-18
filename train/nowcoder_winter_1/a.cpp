#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  while(t--) {
    std::string str; std::cin >> str;
    int a = 0, b = 0;
    int aleft = 5, bleft = 5;
    for(int i = 0; i < 10; ++i) {
      if (i&1) {
        b += str[i]-'0';
        --bleft;
        if (b > a+aleft || b+bleft < a) {
          std::cout << i+1 << NL; goto fend;
        }
      } else {
        a += str[i]-'0';
        --aleft;
        if (a > b+bleft || a+aleft < b) {
          std::cout << i+1 << NL; goto fend;
        }
      }
    }
    std::cout << "-1" << NL;
fend:;
  }
  return 0;
}
