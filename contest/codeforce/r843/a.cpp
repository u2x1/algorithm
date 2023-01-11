#include <iostream>
#include <string>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  int t; std::cin >> t;
  while(t--) {
    std::string a, b, c;
    std::string s;
    std::cin >> s;
    const int len = s.size();
    orep(i, 1, len) {
      orep(j, i+1, len) {
        a = s.substr(0, i);
        b = s.substr(i, j-i);
        c = s.substr(j, len-j);
        if ((a <= b && c <= b) || (a >= b && c >= b)) {
          std::cout << a << " " << b << " " << c << "\n";
          goto fend;
        }
      }
    }
fend:;
  }

  return 0;
}
